#include "stdafx.h"
#include "cMap.h"
#include "cPlayer.h"


cMap::cMap()
{
	//����Ÿ��
	m_pImgMap = g_pImageManager->FindImage("Map");
	//���۸�
	m_pImgMapBuffer = g_pImageManager->FindImage("MapBuffer");
	//m_pImgMap->SetTransColor(true, RGB(255, 0, 255));
	Setup();
}

cMap::~cMap()
{
}

void cMap::Setup()
{
	m_isBlasting = false;
}


void cMap::Update()
{
}

void cMap::Render()
{
	//���� ���ۿ� �׸���.
	m_pImgMap->Render(m_pImgMapBuffer->GetMemDC(), 0, 0, m_pImgMapBuffer->GetWidth(), m_pImgMapBuffer->GetHeight());// m_fBlastPosX, m_fBlastPosY, m_fBlastSize, m_fBlastSize);
	//m_pImgMapBuffer->Render(g_hDC, 0, 0, m_pImgMapBuffer->GetWidth(), m_pImgMapBuffer->GetHeight());
}
