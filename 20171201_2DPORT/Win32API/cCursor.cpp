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
	//타겟을 정해야 하는 경우 
	if (m_pPlayer->GetPlayerBomb2())
		m_pImgCursor->SetFrameX(2);
	//(이동하기 위해)맵을 클릭학 있으면
	if (m_pCamera->GetClickMap())
		m_pImgCursor->SetFrameX(1);
	//둘다 아니면
	if (!m_pPlayer->GetPlayerBomb2() && !m_pCamera->GetClickMap())
		m_pImgCursor->SetFrameX(0);

}

void cCursor::Render()
{
	
	//m_pImgCursor->FrameRender(g_hDC,g_ptMouse.x-CURSOR_SIZE/2,g_ptMouse.y-CURSOR_SIZE, CURSOR_SIZE,CURSOR_SIZE);
	m_pImgCursor->FrameRender(g_hDC, g_ptMouse.x, g_ptMouse.y);
	
}
