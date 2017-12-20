#include "stdafx.h"
#include "cCursor.h"
#include "cCamera.h"
#include "cPlayer.h"


cCursor::cCursor()
{
	m_pImgCursor = g_pImageManager->FindImage("Cursor");
}


cCursor::~cCursor()
{
}

void cCursor::Setup()
{
}

void cCursor::Update()
{
	//Ÿ���� ���ؾ� �ϴ� ��� 
	if (m_pPlayer->GetPlayerBomb2())
		m_pImgCursor->SetFrameX(2);
	//(�̵��ϱ� ����)���� Ŭ���� ������
	if (m_pCamera->GetClickMap())
		m_pImgCursor->SetFrameX(1);
	//�Ѵ� �ƴϸ�
	if (!m_pPlayer->GetPlayerBomb2() && !m_pCamera->GetClickMap())
		m_pImgCursor->SetFrameX(0);

}

void cCursor::Render()
{
	
	//m_pImgCursor->FrameRender(g_hDC,g_ptMouse.x-CURSOR_SIZE/2,g_ptMouse.y-CURSOR_SIZE, CURSOR_SIZE,CURSOR_SIZE);
	m_pImgCursor->FrameRender(g_hDC, g_ptMouse.x, g_ptMouse.y);
	
}
