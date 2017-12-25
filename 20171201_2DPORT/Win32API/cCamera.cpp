#include "stdafx.h"
#include "cCamera.h"



cCamera::cCamera()
{
	//��ü ���۸�
	                
	m_pImgMapBuffer = g_pImageManager->FindImage("MapBuffer");
	//��ü �ڹ��
	m_pImgBG        = g_pImageManager->FindImage("background2");
}

cCamera::~cCamera()
{
}
void cCamera::Setup()
{
	
	m_fMapPosX = 0.0f;
	m_fMapPosY = 0.0f;

	m_fStartPosX = 0.0f;
	m_fStartPosY = 0.0f;
	m_fEndPosX   = 0.0f;
	m_fEndPosY   = 0.0f;
	
	m_fBGPosX = 0.0f;
	m_fBGPosY = 0.0f;

	m_isMoving = false;
	m_isClick = false;

	
}

void cCamera::Update()
{
	//player Ű�̵� �������϶�
	if (!m_isMoving)
	{
		//���콺 Ŭ����ư �Ǵ�
		if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON))
		{
			m_fBefMousePosX = g_ptMouse.x;
			m_fBefMousePosY = g_ptMouse.y;
			m_isClick = true;
		}
		if (g_pKeyManager->isOnceKeyUp(VK_LBUTTON))
		{
			m_isClick = false;
		}
		if (m_isClick)
		{
			//���콺 down ���� ���콺 Up �϶����� �̵��� �Ÿ���
			PlusPosX(m_fBefMousePosX - g_ptMouse.x);
			PlusPosY(m_fBefMousePosY - g_ptMouse.y);
			m_fBefMousePosX = g_ptMouse.x;
			m_fBefMousePosY = g_ptMouse.y;
		}
	}
	//�ڵ�ȭ�� �̵�
	else if (m_isMoving)
	{
		//ī�޶��̵� ��������
		LinearInterpolation(m_fMapPosX, m_fMapPosY, m_fStartPosX, m_fStartPosY, m_fEndPosX, m_fEndPosY, m_fT);
		m_fT += 0.01f; //����������
		if (m_fT > 1.0f)
			m_isMoving = false;

		//����ڵ��̵��� ����
		PlusPosX(0);
		PlusPosY(0);
	}

}



//�ʻ��� �÷��̾� ��ġ 
void cCamera::SetCamera(float centerX, float centerY)
{
	//ī�޶� �̵����̸� ����
	if (m_isMoving) return;

	//ī�޶� y ��Ŀ�� ----------------------------------
	m_fMapPosX = centerX - WINSIZEX / 2;

	if (m_fMapPosX > m_pImgMapBuffer->GetWidth() - WINSIZEX)
	{
		//player�� �߽��� �Ѿ�� ī�޶�� �߽������� 
		//�������� �ʰ� �����Ѵ�.
		m_fMapPosX = m_pImgMapBuffer->GetWidth() - WINSIZEX;
	}
	else if (m_fMapPosX < 0)
		m_fMapPosX = 0.0f;


	//ī�޶� Y��Ŀ�� ------------------------------------------
	m_fMapPosY = centerY - WINSIZEY / 2;
	if (m_fMapPosY > m_pImgMapBuffer->GetHeight() - WINSIZEY)
	{
		m_fMapPosY = m_pImgMapBuffer->GetHeight() - WINSIZEY;
	}
	else if (m_fMapPosY < 0)
		m_fMapPosY = 0.0f;

	//�����ġ ����----�ڹ�� �������� �ʰ� �Ұ�� �ʿ� ����
	m_fBGPosX = m_fMapPosX / m_pImgMapBuffer->GetWidth()*(m_pImgBG->GetWidth() - WINSIZEX);
	m_fBGPosY = m_fMapPosY / m_pImgMapBuffer->GetHeight()*(m_pImgBG->GetHeight() - WINSIZEY);

}

void cCamera::MoveCamera(float centerX,float centerY)
{
	//�ʻ��� ��ġ�� ����ī�޶� ��ġ�� ����
	m_fStartPosX = m_fMapPosX;
	m_fStartPosY = m_fMapPosY;
	m_fEndPosX = centerX - WINSIZEX / 2;

	if (m_fEndPosX > m_pImgMapBuffer->GetWidth() - WINSIZEX)
		m_fEndPosX = m_pImgMapBuffer->GetWidth() - WINSIZEX;
	else if (m_fEndPosX < 0)
		m_fEndPosX = 0.0f;

	m_fEndPosY = centerY - WINSIZEY / 2;
	if (m_fEndPosY > m_pImgMapBuffer->GetHeight() - WINSIZEY)
		m_fEndPosY = m_pImgMapBuffer->GetHeight() - WINSIZEY;
	else if (m_fEndPosY < 0)
		m_fEndPosY = 0.0f;

	m_isMoving = true;
	m_fT = 0.0f;

}

void cCamera::PlusPosY(float plus)
{
	m_fMapPosY += plus;
	if (m_fMapPosY > m_pImgMapBuffer->GetHeight() - WINSIZEY)
		m_fMapPosY = m_pImgMapBuffer->GetHeight() - WINSIZEY;
	else if (m_fMapPosY < 0)
		m_fMapPosY = 0.0f;

	//��ü�ڹ�濡��  ��ġ ����
	//                           �ʹ���                      (��ü���ũ�� - ȭ��ũ��)
	m_fBGPosY = m_fMapPosY / m_pImgMapBuffer->GetHeight() * (m_pImgBG->GetHeight() - WINSIZEY);
}

void cCamera::PlusPosX(float plus)
{
	m_fMapPosX += plus;
	if (m_fMapPosX > m_pImgMapBuffer->GetHeight() - WINSIZEY)
		m_fMapPosX = m_pImgMapBuffer->GetHeight() - WINSIZEY;
	else if (m_fMapPosX < 0)
		m_fMapPosX = 0.0f;

	//��ü�ڿ��� ��� ��ġ ����
	m_fBGPosX = m_fMapPosX / m_pImgMapBuffer->GetWidth() * (m_pImgBG->GetHeight() - WINSIZEX);
}

