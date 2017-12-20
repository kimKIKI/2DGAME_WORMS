#include "stdafx.h"
#include "cWormScene.h"
#include "cPlayer.h"
#include "cMap.h"
#include "cCamera.h"
#include "cCursor.h"



void cWormScene::Setup()
{
	
	//전체 뒤배경------------------------------------------------------
	//m_pMap = g_pImageManager->FindImage("bg");
	//magenta
	//m_pImgMapBuffer->SetTransColor(true, RGB(255, 0, 255)); ERROR
	//마젠타맵
	
	//맵 빈버퍼
	m_pImgMapBuffer = g_pImageManager->FindImage("MapBuffer");
	m_pImgMapBuffer->SetTransColor(true, RGB(255,0,255));

	//뒷배경
	//m_pBackGround = g_pImageManager->FindImage("background");
	m_pBackGroundBMP = g_pImageManager->FindImage("background2");
	//------------------------------------------------------------------
	     
	m_pPlayer = new cPlayer;
	m_pMap    = new cMap;
	m_pCamera = new cCamera;
	m_pCursor = new cCursor;

	//상호참조
	m_pPlayer->SetMap(m_pMap);
	m_pPlayer->SetCamera(m_pCamera);

	m_pMap->SetPlayer(m_pPlayer);
	m_pPlayer->Setup();
	m_pMap->Setup();
	m_pCamera->Setup();
	m_pCursor->SetCamera(m_pCamera);
	m_pCursor->SetPlayer(m_pPlayer);
}

void cWormScene::Update()
{
	cGameNode::Update();
	//각씬의 상태를 분류한다
	//게임시작 -->>player의 상태를 fall로 바꿈
	//턴시작
	//카운트
	//다음턴
	//UI활성화
	//UI꺼짐
	
	m_pMap->Update();
	m_pPlayer->Update();
	m_pCamera->Update();
	m_pCursor->Update();


}

void cWormScene::Render()
{
	
	char strA[128];
	wsprintf(strA,"현재씬은 WORM1씬 입니다.");
	TextOut(g_hDC, 100, 100, strA, lstrlen(strA));
	
	// 흰색으로 이미지를 칠한다.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);


	//m_pBackGround->Render(g_hDC,800,800);
	 m_pBackGroundBMP->Render(g_hDC,m_pCamera->GetBGDestX() ,m_pCamera->GetBGDestY(),WINSIZEX*2,WINSIZEY+WINSIZEY/2);
	//클래스변수
	 m_pImgMapBuffer->Render(g_hDC,m_pCamera->GetMapDestX(),m_pCamera->GetMapDestY());
	 m_pMap->Render();
	 m_pPlayer->Render();
	 m_pCursor->Render();
	 
}

void cWormScene::Release()
{
	
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMap);
	SAFE_DELETE(m_pCamera);
	SAFE_DELETE(m_pCursor);
}
