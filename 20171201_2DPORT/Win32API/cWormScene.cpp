#include "stdafx.h"
#include "cWormScene.h"
#include "cPlayer.h"
#include "cMap.h"
#include "cCamera.h"
#include "cCursor.h"



void cWormScene::Setup()
{
	
	//��ü �ڹ��------------------------------------------------------
	//m_pMap = g_pImageManager->FindImage("bg");
	//magenta
	//m_pImgMapBuffer->SetTransColor(true, RGB(255, 0, 255)); ERROR
	//����Ÿ��
	
	//�� �����
	m_pImgMapBuffer = g_pImageManager->FindImage("MapBuffer");
	m_pImgMapBuffer->SetTransColor(true, RGB(255,0,255));

	//�޹��
	//m_pBackGround = g_pImageManager->FindImage("background");
	m_pBackGroundBMP = g_pImageManager->FindImage("background2");
	//------------------------------------------------------------------
	     
	m_pPlayer = new cPlayer;
	m_pMap    = new cMap;
	m_pCamera = new cCamera;
	m_pCursor = new cCursor;

	//��ȣ����
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
	//������ ���¸� �з��Ѵ�
	//���ӽ��� -->>player�� ���¸� fall�� �ٲ�
	//�Ͻ���
	//ī��Ʈ
	//������
	//UIȰ��ȭ
	//UI����
	
	m_pMap->Update();
	m_pPlayer->Update();
	m_pCamera->Update();
	m_pCursor->Update();


}

void cWormScene::Render()
{
	
	char strA[128];
	wsprintf(strA,"������� WORM1�� �Դϴ�.");
	TextOut(g_hDC, 100, 100, strA, lstrlen(strA));
	
	// ������� �̹����� ĥ�Ѵ�.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);


	//m_pBackGround->Render(g_hDC,800,800);
	 m_pBackGroundBMP->Render(g_hDC,m_pCamera->GetBGDestX() ,m_pCamera->GetBGDestY(),WINSIZEX*2,WINSIZEY+WINSIZEY/2);
	//Ŭ��������
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
