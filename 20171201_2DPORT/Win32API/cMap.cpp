#include "stdafx.h"
#include "cMap.h"
#include "cPlayer.h"




void cMap::Setup()
{
	//����Ÿ��
	m_pImgMap = g_pImageManager->FindImage("Map");
	//���۸�
	m_pImgMapBuffer = g_pImageManager->FindImage("MapBuffer");
	m_pImgMap->SetTransColor(true, RGB(255, 0, 255));
}

void cMap::Update()
{
}

void cMap::Render()
{
	//���� ���ۿ� �׸���.
	m_pImgMap->Render(m_pImgMapBuffer->GetMemDC(), m_fBlastPosX, m_fBlastPosY, m_fBlastSize, m_fBlastSize);

}
