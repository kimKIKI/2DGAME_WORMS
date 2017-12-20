#include "stdafx.h"
#include "cCamera.h"


cCamera::cCamera()
{
	//전체 버퍼맵
	m_ImgMapBuffer = g_pImageManager->FindImage("MapBufer");
	//전체 뒤배경
	m_imgBG = g_pImageManager->FindImage("background2");
	
}

cCamera::~cCamera()
{
}
void cCamera::Setup()
{

}

void cCamera::Update()
{

}

void cCamera::SetCamera(float centerX,float centerY)
{

}
void cCamera::MoveCamera(float centerX,float centerY)
{

}