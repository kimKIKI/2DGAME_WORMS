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
	//Worm���� ����� ���
	m_pPlayer = new cPlayer;
	m_pMap = g_pImageManager->FindImage("bg");
	m_pPlayer->Setup();

}

void cWormScene::Update()
{

	//������ ���¸� �з��Ѵ�
	//���ӽ��� -->>player�� ���¸� fall�� �ٲ�
	//�Ͻ���
	//ī��Ʈ
	//������
	//UIȰ��ȭ
	//UI����
	m_pPlayer->Update();
	
}

void cWormScene::Render()
{
	
	char strA[128];
	wsprintf(strA,"������� WORM1�� �Դϴ�.");
	TextOut(g_hDC, 100, 100, strA, lstrlen(strA));
	m_pMap->Render(g_hDC, 0, 0, 800, 600);

	//Ŭ��������
	m_pPlayer->Render();
	
}

void cWormScene::Release()
{
	delete m_pPlayer;
}
