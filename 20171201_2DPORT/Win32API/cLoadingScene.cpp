#include "stdafx.h"
#include "cLoadingScene.h"


void cLoadingScene::Setup()
{
	m_pLoading = new cLoading;
	m_pLoading->Setup();

	LoadingImage();
	LoadingSound();
}

void cLoadingScene::Update()
{
	// m_pLoading->LoadingDone() : 실질 적인 리소스 로딩과 프로그레스바 업데이트
	if (m_pLoading->LoadingDone())
	{
		g_pSceneManager->ChangeScene(g_pSceneManager->GetNextScene());
	}
}

void cLoadingScene::Render()
{
	m_pLoading->Render();
}

void cLoadingScene::Release()
{
	SAFE_DELETE(m_pLoading);
}

void cLoadingScene::LoadingImage()
{
	char szBuf[32];
	char* str;

	/* ==== 리소스 해제 ===== */
	
	g_pImageManager->ReleaseImage("Worm2");
	g_pImageManager->ReleaseImage("Worm1");
	g_pImageManager->ReleaseImage("bg");


	/* ====================== */

	// 게임 전체에서 필요한 리소스는 타이틀 씬 로딩에서 전부 로드한다.
	switch (g_pSceneManager->GetNextScene())
	{
	case SLIST_TITLE:

		break;
	case SLIST_PLAY:

	
	

		break;

	case SLIST_WORM1:
		ifstream i;
		i.open("data/resourceMap.json",ios_base::in);
		m_pLoading->LoadFrameImage("kworm_walkAll", "images/state/WALK/wwalkAll.png", 360, 900, 6, 15, true, RGB(255, 0, 255));
		  //좌걷기
		m_pLoading->LoadFrameImage("kworm_walk","images/state/WALK/wwalk.png", 60, 900, 1, 15, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("kworm_walkd", "images/state/WALK/wwalkd.png", 60, 900, 1, 15, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("kworm_walku", "images/state/WALK/wwalku.png", 60, 900, 1, 15, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("kworm_whrhcl", "images/state/ATK/wthrhcl.png", 60, 1920, 1, 30, true, RGB(255, 0, 255));

		  //좌 경사면
		//m_pLoading->LoadFrameImage("Worm_", "images/wpbrtlku.png", 60, 900, 1, 15, true, RGB(255, 0, 255));
		  //좌경사 고개숙이기
		//m_pLoading->LoadFrameImage("Worm_lowhead", "images/wpbrtlkd.png", 60, 900, 1, 15, true, RGB(255, 0, 255));
		  //좌 뒤도면윙크
		//m_pLoading->LoadFrameImage("Worm_winkD", "images/wpeekD.png", 60,1020, 1, 17, true, RGB(255, 0, 255));
		  //윙크
		//m_pLoading->LoadFrameImage("Worm1","images/wpeek.png", 60, 1020, 1, 17, true, RGB(255, 0, 255));
		//m_pImgMapBuffer = g_pImageManager->AddImage("MapBuffer", WINSIZEX * 2, WINSIZEY + WINSIZEY / 2);
		//m_pImgMapBuffer->SetTransColor(true, RGB(255, 0, 255)); //빈 맵버퍼 생성, 마젠타값 빼기 true


		//마젠타 있는 맵 3000,1500
		m_pLoading->LoadImageFile("Map","images/warm.bmp", WINSIZEX * 2, WINSIZEY + WINSIZEY / 2);
		//빈버퍼
		m_pLoading->LoadEmpty("MapBuffer", WINSIZEX * 2, WINSIZEY + WINSIZEY / 2);
		//뒷배경 **이미지를 늘려서 쓸경우  수정된 png cImage를 쓰지말것
		m_pLoading->LoadBmpFile("background2","images/back2.bmp",256,256,false,RGB(255,0,255));
		m_pLoading->LoadFrameImage("Cursor", "images/Cursor.bmp", 49,16,3,1,true,RGB(255,0,255));
	
		break;
		
	}
}

void cLoadingScene::LoadingSound()
{
	switch (g_pSceneManager->GetNextScene())
	{
	case SLIST_TITLE:

		break;
	case SLIST_PLAY:



		break;
	}
}