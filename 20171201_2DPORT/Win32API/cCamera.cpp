#include "stdafx.h"
#include "cCamera.h"


cCamera::cCamera()
{
	//��ü ���۸�
	m_ImgMapBuffer = g_pImageManager->FindImage("MapBufer");
	//��ü �ڹ��
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