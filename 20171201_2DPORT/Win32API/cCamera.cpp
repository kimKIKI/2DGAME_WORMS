#include "stdafx.h"
#include "cCamera.h"



cCamera::cCamera()
{
	//전체 버퍼맵
	                
	m_pImgMapBuffer = g_pImageManager->FindImage("MapBuffer");
	//전체 뒤배경
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
	//player 키이동 움직임일때
	if (!m_isMoving)
	{
		//마우스 클릭버튼 판단
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
			//마우스 down 에서 마우스 Up 일때까지 이동한 거리값
			PlusPosX(m_fBefMousePosX - g_ptMouse.x);
			PlusPosY(m_fBefMousePosY - g_ptMouse.y);
			m_fBefMousePosX = g_ptMouse.x;
			m_fBefMousePosY = g_ptMouse.y;
		}
	}
	//자동화면 이동
	else if (m_isMoving)
	{
		//카메라이동 선형보간
		LinearInterpolation(m_fMapPosX, m_fMapPosY, m_fStartPosX, m_fStartPosY, m_fEndPosX, m_fEndPosY, m_fT);
		m_fT += 0.01f; //선형보간율
		if (m_fT > 1.0f)
			m_isMoving = false;

		//배경자동이동을 위해
		PlusPosX(0);
		PlusPosY(0);
	}

}



//맵상의 플레이어 위치 
void cCamera::SetCamera(float centerX, float centerY)
{
	//카메라 이동중이면 리턴
	if (m_isMoving) return;

	//카메라 y 포커스 ----------------------------------
	m_fMapPosX = centerX - WINSIZEX / 2;

	if (m_fMapPosX > m_pImgMapBuffer->GetWidth() - WINSIZEX)
	{
		//player가 중심을 넘어서면 카메라는 중심점에서 
		//움직이지 않게 고정한다.
		m_fMapPosX = m_pImgMapBuffer->GetWidth() - WINSIZEX;
	}
	else if (m_fMapPosX < 0)
		m_fMapPosX = 0.0f;


	//카메라 Y포커스 ------------------------------------------
	m_fMapPosY = centerY - WINSIZEY / 2;
	if (m_fMapPosY > m_pImgMapBuffer->GetHeight() - WINSIZEY)
	{
		m_fMapPosY = m_pImgMapBuffer->GetHeight() - WINSIZEY;
	}
	else if (m_fMapPosY < 0)
		m_fMapPosY = 0.0f;

	//배경위치 세팅----뒤배경 움직이지 않게 할경우 필요 없음
	m_fBGPosX = m_fMapPosX / m_pImgMapBuffer->GetWidth()*(m_pImgBG->GetWidth() - WINSIZEX);
	m_fBGPosY = m_fMapPosY / m_pImgMapBuffer->GetHeight()*(m_pImgBG->GetHeight() - WINSIZEY);

}

void cCamera::MoveCamera(float centerX,float centerY)
{
	//맵상의 위치를 현재카메라 위치로 변경
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

	//전체뒤배경에서  위치 셋팅
	//                           맵버퍼                      (전체배경크기 - 화면크기)
	m_fBGPosY = m_fMapPosY / m_pImgMapBuffer->GetHeight() * (m_pImgBG->GetHeight() - WINSIZEY);
}

void cCamera::PlusPosX(float plus)
{
	m_fMapPosX += plus;
	if (m_fMapPosX > m_pImgMapBuffer->GetHeight() - WINSIZEY)
		m_fMapPosX = m_pImgMapBuffer->GetHeight() - WINSIZEY;
	else if (m_fMapPosX < 0)
		m_fMapPosX = 0.0f;

	//전체뒤에서 배경 위치 셋팅
	m_fBGPosX = m_fMapPosX / m_pImgMapBuffer->GetWidth() * (m_pImgBG->GetHeight() - WINSIZEX);
}

