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
	// m_pLoading->LoadingDone() : ���� ���� ���ҽ� �ε��� ���α׷����� ������Ʈ
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

	/* ==== ���ҽ� ���� ===== */
	
	g_pImageManager->ReleaseImage("Worm2");
	g_pImageManager->ReleaseImage("Worm1");
	g_pImageManager->ReleaseImage("bg");


	/* ====================== */

	// ���� ��ü���� �ʿ��� ���ҽ��� Ÿ��Ʋ �� �ε����� ���� �ε��Ѵ�.
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
		  //�°ȱ�
		m_pLoading->LoadFrameImage("kworm_walk","images/state/WALK/wwalk.png", 60, 900, 1, 15, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("kworm_walkd", "images/state/WALK/wwalkd.png", 60, 900, 1, 15, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("kworm_walku", "images/state/WALK/wwalku.png", 60, 900, 1, 15, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("kworm_whrhcl", "images/state/ATK/wthrhcl.png", 60, 1920, 1, 30, true, RGB(255, 0, 255));

		  //�� ����
		//m_pLoading->LoadFrameImage("Worm_", "images/wpbrtlku.png", 60, 900, 1, 15, true, RGB(255, 0, 255));
		  //�°�� �����̱�
		//m_pLoading->LoadFrameImage("Worm_lowhead", "images/wpbrtlkd.png", 60, 900, 1, 15, true, RGB(255, 0, 255));
		  //�� �ڵ�����ũ
		//m_pLoading->LoadFrameImage("Worm_winkD", "images/wpeekD.png", 60,1020, 1, 17, true, RGB(255, 0, 255));
		  //��ũ
		//m_pLoading->LoadFrameImage("Worm1","images/wpeek.png", 60, 1020, 1, 17, true, RGB(255, 0, 255));
		//m_pImgMapBuffer = g_pImageManager->AddImage("MapBuffer", WINSIZEX * 2, WINSIZEY + WINSIZEY / 2);
		//m_pImgMapBuffer->SetTransColor(true, RGB(255, 0, 255)); //�� �ʹ��� ����, ����Ÿ�� ���� true


		//����Ÿ �ִ� �� 3000,1500
		m_pLoading->LoadImageFile("Map","images/warm.bmp", WINSIZEX * 2, WINSIZEY + WINSIZEY / 2);
		//�����
		m_pLoading->LoadEmpty("MapBuffer", WINSIZEX * 2, WINSIZEY + WINSIZEY / 2);
		//�޹�� **�̹����� �÷��� �����  ������ png cImage�� ��������
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