#include "stdafx.h"
#include "cPlayer.h"
#include "cMap.h"
#include "cCamera.h"


#define PLAYER_SIZE_X		50.0f
#define PLAYER_SIZE_Y		40.0f
#define PLAYER_MAX_COUNT	4
#define PLAYER_ANIM_COUNT   4


void cPlayer::Setup()
{

#pragma region wormSprite
	//m_pImgMapBuffer = g_pImageManager->FindImage("MapBuffer");
	//m_pImgMapBuffer->SetTransColor(true,RGB(255,0,255)); ERROR
	//m_imgPlayer = g_pImageManager->FindImage("Worm1");
	//m_imgPlayer = g_pImageManager->FindImage("kworm_walk");
	//m_imgPlayer = g_pImageManager->FindImage("kworm_walkd");
	//m_imgPlayer = g_pImageManager->FindImage("Worm2");
	//m_imgPlayer = g_pImageManager->FindImage("kworm_thrhcl");

#pragma endregion

	m_pImgPlayer = g_pImageManager->FindImage("kworm_walkAll");
	m_pImgMapBuffer = g_pImageManager->FindImage("MapBuffer");
	m_pImgMapBuffer->SetTransColor(true, RGB(255, 0, 255));


	m_eState = null; //enum 초기 
	m_iFrameX = 0;   //캐릭터  프레임  0

	m_Player[0].nPlayerNo = 0;
	m_Player[0].fPosX = m_pImgMapBuffer->GetWidth() / 5.0f;
	m_Player[0].fPosY = m_pImgMapBuffer->GetHeight() / 3.0f;
	m_Player[0].isRight = true;
	m_Player[0].fSpeed = 3.0f;

	m_pCamera->SetCamera(m_Player[0].fPosX + PLAYER_SIZE_X/2,
		                 m_Player[0].fPosY + PLAYER_SIZE_Y/2);
}
void cPlayer::Update()
{	
	 PlayerController();
	 CheckPixel();
	// cout << " X :" << m_Player[0].fPosX << "---" << m_Player[0].fPosY << endl;
	
}

void cPlayer::Render()
{
	//Worm1 
	//m_imgPlayer->FrameRender(g_hDC, 100, 100, 0, 0, 0, 16, 3);
	//Worm2
	//m_imgPlayer->FrameRender(g_hDC, 100, 100, 0, 0, 0, 14, 1);
	//         인덱스     0<-, 1<-하,2<-상, 3-> ,4->하, 5->상     
	
	//처음 시작  스프라이트 
	//m_pImgPlayer->FrameRender(g_hDC, 100, 100, m_iFrameX, 0, m_iFrameX, 0, 2);
	m_pImgPlayer->SetFrameX(m_Player[0].isRight);
	m_pImgPlayer->SetFrameY(0);
	m_pImgPlayer->AlphaFrameRender(g_hDC, m_pCamera->GetMapDestX() + m_Player[0].fPosX, m_pCamera->GetMapDestY() + m_Player[0].fPosY, m_Player[0].Alpha);
	//m_pImgPlayer->AlphaFrameRender(g_hDC, m_Player[0].fPosX, m_Player[0].fPosY, m_Player[0].Alpha);


	//키입력이 없을때는 움직여서는 안된다.
	//Worm_WinkD
	//m_imgPlayer->FrameRender(g_hDC, 100, 100, 0, 0, 0, 16, 3);


	//m_pImgMapBuffer->Render(g_hDC);
}



void cPlayer::CheckPixel()
{
	//왼쪽 중간
	m_Player[0].fprobeX3 = m_Player[0].fPosX + PLAYER_SIZE_X / 4;
	m_Player[0].fprobeY3 = m_Player[0].fPosY + PLAYER_SIZE_Y / 2;
	//오른쪽 중간
	m_Player[0].fprobeX4 = m_Player[0].fPosX + PLAYER_SIZE_X / 4 * 3;
	m_Player[0].fprobeY4 = m_Player[0].fPosY + PLAYER_SIZE_Y / 2;
	//왼쪽 아래
	m_Player[0].fprobeX5 = m_Player[0].fPosX + PLAYER_SIZE_X / 4;
	m_Player[0].fprobeY5 = m_Player[0].fPosY + PLAYER_SIZE_Y;
	//오른쪽 아래
	m_Player[0].fprobeX6 = m_Player[0].fPosX + PLAYER_SIZE_X / 4 * 3;
	m_Player[0].fprobeY6 = m_Player[0].fPosY + PLAYER_SIZE_Y;

	 //왼쪽 중간이 마젠타가 아니라면
	if (!g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX3 - m_Player[0].fSpeed, m_Player[0].fprobeY3)) //왼쪽 중간이 마젠타가 아니라면
	{
		m_Player[0].fPosX += m_Player[0].fSpeed;
	}
	//중간 오른쪽 픽셀 체크
	if (!g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX4 + m_Player[0].fSpeed, m_Player[0].fprobeY4)) //오른쪽 중간이 마젠타가 아니라면
	{
		
			m_Player[0].fPosX -= m_Player[0].fSpeed;
	}

	//아래 픽셀 체크
	if (g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX5, m_Player[0].fprobeY5)
		&& g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX6, m_Player[0].fprobeY6)) //두 아래가 마젠타면
	{
		    PlusPlayerPosY(m_Player[0].fSpeed);
			//m_Player[0].fPosY += m_Player[0].fSpeed;
	}
	else if (!g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX5, m_Player[0].fprobeY5 - m_Player[0].fSpeed)
		|| !g_pPixelManager->CheckPixel(m_pImgMapBuffer, m_Player[0].fprobeX6, m_Player[0].fprobeY6 - m_Player[0].fSpeed)) //하나의 아래가 마젠타가 아니면
	{
		      PlusPlayerPosY(-m_Player[0].fSpeed);
			 //m_Player[0].fPosY -= m_Player[0].fSpeed;
	}

	
} //method END

//플레이어 X위치 이동
void cPlayer::PlusPlayerPosX(float plus)
{
	m_Player[0].fPosX += plus;
	//SetPlayerCamera(false);
}

//플레이어 Y위치 이동
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
		//m_pImgPlayer->SetFrameX(0);
		if(m_Player[0].fPosX >= m_Player[0].fSpeed)
		PlusPlayerPosX(-m_Player[0].fSpeed);

	}
	else if (g_pKeyManager->isStayKeyDown('D'))
	{

		//x 3,4,5
		int num = 20;
		cout << num << endl;
		//m_pImgPlayer->SetFrameX(3);
		PlusPlayerPosX(m_Player[0].fSpeed);

		if (m_Player[0].fPosX <= m_pImgMapBuffer->GetWidth() - PLAYER_SIZE_X - m_Player[0].fSpeed)
		{
			PlusPlayerPosX(m_Player[0].fSpeed); 
		}

	}
	else if (g_pKeyManager->isOnceKeyDown('W'))
	{
		//조준상

		
	}
	else if (g_pKeyManager->isOnceKeyDown('D'))
	{
		//조준하
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_SPACE))
	{
		//DEBUG 잘찍히고 있나 확인
		cout << "체크포인트좌표 x:" << m_Player[0].fprobeX3 << "- Y" << m_Player[0].fprobeY3 << endl;
		cout << "체크포인트좌표 x:" << m_Player[0].fprobeX4 << "- Y" << m_Player[0].fprobeY4 << endl;
		cout << "체크포인트좌표 x:" << m_Player[0].fprobeX5 << "- Y" << m_Player[0].fprobeY5 << endl;
		cout << "체크포인트좌표 x:" << m_Player[0].fprobeX6 << "- Y" << m_Player[0].fprobeY6 << endl;
	}

	//aimatin 
	switch (m_eState)
	{
	case cPlayer::null:

		m_iFrameX = 0; //프레임랜더의 x열에 접근해서 동작을 다르게 한다.
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
