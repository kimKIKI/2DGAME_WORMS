#include "stdafx.h"
#include "cWormScene.h"
#include "cPlayer.h"

cWormScene::cWormScene()
{
	//Setup();
}

cWormScene::~cWormScene()
{
}

void cWormScene::Setup()
{
	//Worm에서 사용할 배경
	m_pPlayer = new cPlayer;
	m_pMap = g_pImageManager->FindImage("bg");
	m_pPlayer->Setup();

}

void cWormScene::Update()
{

	//각씬의 상태를 분류한다
	//게임시작 -->>player의 상태를 fall로 바꿈
	//턴시작
	//카운트
	//다음턴
	//UI활성화
	//UI꺼짐
	m_pPlayer->Update();
	
}

void cWormScene::Render()
{
	
	char strA[128];
	wsprintf(strA,"현재씬은 WORM1씬 입니다.");
	TextOut(g_hDC, 100, 100, strA, lstrlen(strA));
	m_pMap->Render(g_hDC, 0, 0, 800, 600);

	//클래스변수
	m_pPlayer->Render();
	
}

void cWormScene::Release()
{
	delete m_pPlayer;
}
