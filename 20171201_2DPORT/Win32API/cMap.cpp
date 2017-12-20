#include "stdafx.h"
#include "cMap.h"
#include "cPlayer.h"




void cMap::Setup()
{
	//¸¶Á¨Å¸¸Ê
	m_pImgMap = g_pImageManager->FindImage("Map");
	//¹öÆÛ¸Ê
	m_pImgMapBuffer = g_pImageManager->FindImage("MapBuffer");
	m_pImgMap->SetTransColor(true, RGB(255, 0, 255));
}

void cMap::Update()
{
}

void cMap::Render()
{
	//¸ÊÀ» ¹öÆÛ¿¡ ±×¸°´Ù.
	m_pImgMap->Render(m_pImgMapBuffer->GetMemDC(), m_fBlastPosX, m_fBlastPosY, m_fBlastSize, m_fBlastSize);

}
