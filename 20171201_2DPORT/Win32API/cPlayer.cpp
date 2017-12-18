#include "stdafx.h"
#include "cPlayer.h"

#define PLAYER_SIZE_X		50.0f
#define PLAYER_SIZE_Y		40.0f
#define PLAYER_MAX_COUNT	4
#define PLAYER_ANIM_COUNT   4



void cPlayer::Update()
{	
	 PlayerController();
	 CheckPixel();
	
}

void cPlayer::Render()
{
	//Worm1 
	//m_imgPlayer->FrameRender(g_hDC, 100, 100, 0, 0, 0, 16, 3);
	//Worm2
	//m_imgPlayer->FrameRender(g_hDC, 100, 100, 0, 0, 0, 14, 1);
	//         �ε���     0<-, 1<-��,2<-��, 3-> ,4->��, 5->��     
	
	//ó�� ����  ��������Ʈ 
	//m_pImgPlayer->FrameRender(g_hDC, 100, 100, m_iFrameX, 0, m_iFrameX, 0, 2);
	m_pImgPlayer->SetFrameX(m_Player[0].isRight);
	m_pImgPlayer->SetFrameY(0);
	//m_pImgPlayer->AlphaFrameRender(g_hDC, m_pCamera->GetMapDestX() + m_Player[0].fPosX, m_pCamera->GetMapDestY() + m_Player[0].fPosY, m_Player[0].Alpha);
	m_pImgPlayer->AlphaFrameRender(g_hDC, 0, 0, m_Player[0].Alpha);


	//Ű�Է��� �������� ���������� �ȵȴ�.
	//Worm_WinkD
	//m_imgPlayer->FrameRender(g_hDC, 100, 100, 0, 0, 0, 16, 3);
}

void cPlayer::Setup()
{
	m_pImgMapBuffer = g_pImageManager->FindImage("MapBuffer");
	m_pImgMapBuffer->SetTransColor(true,RGB(255,0,255));

	//m_imgPlayer = g_pImageManager->FindImage("Worm1");
	//m_imgPlayer = g_pImageManager->FindImage("kworm_walk");
	//m_imgPlayer = g_pImageManager->FindImage("kworm_walkd");
	m_pImgPlayer = g_pImageManager->FindImage("kworm_walkAll");
	//m_imgPlayer = g_pImageManager->FindImage("Worm2");
	//m_pImageBuffer = g_pImageManager->FindImage("bg");

	//�ܳ��ϴ�.
	//m_imgPlayer = g_pImageManager->FindImage("kworm_thrhcl");

	m_eState = null; //enum �ʱ� 
	m_iFrameX = 0;   //ĳ����  ������  0

	m_Player[0].nPlayerNo = 0;
	m_Player[0].fPosX = 200;
	m_Player[0].fPosY = 200;
	m_Player[0].isRight = true;
	m_Player[0].fSpeed = 3.0f;
}

void cPlayer::CheckPixel()
{
	//���� �߰�
	m_Player[0].fprobeX3 = m_Player[0].fPosX + PLAYER_SIZE_X / 4;
	m_Player[0].fprobeY3 = m_Player[0].fPosY + PLAYER_SIZE_Y / 2;
	//������ �߰�
	m_Player[0].fprobeX4 = m_Player[0].fPosX + PLAYER_SIZE_X / 4 * 3;
	m_Player[0].fprobeY4 = m_Player[0].fPosY + PLAYER_SIZE_Y / 2;
	//���� �Ʒ�
	m_Player[0].fprobeX5 = m_Player[0].fPosX + PLAYER_SIZE_X / 4;
	m_Player[0].fprobeY5 = m_Player[0].fPosY + PLAYER_SIZE_Y;
	//������ �Ʒ�
	m_Player[0].fprobeX6 = m_Player[0].fPosX + PLAYER_SIZE_X / 4 * 3;
	m_Player[0].fprobeY6 = m_Player[0].fPosY + PLAYER_SIZE_Y;

	 //���� �߰��� ����Ÿ�� �ƴ϶��
	if (!g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX3 - m_Player[0].fSpeed, m_Player[0].fprobeY3)) //���� �߰��� ����Ÿ�� �ƴ϶��
	{
		m_Player[0].fPosX += m_Player[0].fSpeed;
	}
	//�߰� ������ �ȼ� üũ
	if (!g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX4 + m_Player[0].fSpeed, m_Player[0].fprobeY4)) //������ �߰��� ����Ÿ�� �ƴ϶��
	{
		
			m_Player[0].fPosX -= m_Player[0].fSpeed;
	}

	//�Ʒ� �ȼ� üũ
	if (g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX5, m_Player[0].fprobeY5)
		&& g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX6, m_Player[0].fprobeY6)) //�� �Ʒ��� ����Ÿ��
	{
		
			m_Player[0].fPosY += m_Player[0].fSpeed;
	}
	else if (!g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX5, m_Player[0].fprobeY5 - m_Player[0].fSpeed)
		|| !g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX6, m_Player[0].fprobeY6 - m_Player[0].fSpeed)) //�ϳ��� �Ʒ��� ����Ÿ�� �ƴϸ�
	{
			m_Player[0].fPosY -= m_Player[0].fSpeed;
	}

	
} //method END

//�÷��̾� X��ġ �̵�
void cPlayer::PlusPlayerPosX(float plus)
{
	m_Player[0].fPosX += plus;
	//SetPlayerCamera(false);
}

//�÷��̾� Y��ġ �̵�
void cPlayer::PlusPlayerPosY(float plus)
{
	m_Player[0].fPosY += plus;
	//SetPlayerCamera(false);
}

void cPlayer::PlayerController()
{
	if (g_pKeyManager->isStayKeyDown('A'))
	{
		

		int num = 10;
		cout << num << endl;
		//x 0,1,2,
		m_pImgPlayer->SetFrameX(0);

		PlusPlayerPosX(-m_Player[0].fSpeed);

	}
	else if (g_pKeyManager->isStayKeyDown('D'))
	{

		//x 3,4,5
		int num = 20;
		cout << num << endl;
		m_pImgPlayer->SetFrameX(3);
		PlusPlayerPosX(m_Player[0].fSpeed);

	}
	else if (g_pKeyManager->isOnceKeyDown('W'))
	{
		//���ػ�
	}
	else if (g_pKeyManager->isOnceKeyDown('D'))
	{
		//������
	}

	//aimatin 
	switch (m_eState)
	{
	case cPlayer::null:

		m_iFrameX = 0; //�����ӷ����� x���� �����ؼ� ������ �ٸ��� �Ѵ�.
		break;
	case cPlayer::player_Idle:
		m_iFrameX = 0;
		break;
	case cPlayer::player_Atk:

		break;

	case cPlayer::player_Walk:

		break;
	case cPlayer::player_End:

		break;

	}

}