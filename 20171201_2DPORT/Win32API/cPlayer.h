#pragma once
class cWormScene;
class cMap;
class cCamera;


#define PLAYER_MAX_COUNT 4
#define PLAYER_SIZE_X		50.0f
#define PLAYER_SIZE_Y		40.0f
#define BOMB_SIZE           30.0f
#define BOMB2_DELAY         60
 
struct tagPlayer {

	int      nPlayerNo;
	int      isRight;
	int      nBomb2Count;
	int      nBomb3Count;

	float    fPosX;
	float    fPosY;
	float    fprobeX3; //왼쪽중간
	float    fprobeY3;  
	float    fprobeX4; //오른쪽중간
	float    fprobeY4;
	float    fprobeX5; //왼쪽아래
	float    fprobeY5; 
	float    fprobeX6; //오른쪽아래
	float    fprobeY6;
	float	 fSpeed;   //speed



	BYTE     Alpha;
};

class cPlayer
{


private:

	enum ePlayerAime
	{
		null,
		player_Idle,			// 빈 비트맵 로딩
		player_Walk,			// 파일로 로딩
		player_Atk,
		player_Aiming,          //겨낭하다.
		player_Die,
		player_End,


	};

	tagPlayer      m_Player[PLAYER_MAX_COUNT];
	RECT 	       m_rtPlayer;
	cImage*        m_pImgPlayer;      //warm 이미지
	cImage*		   m_pImgMapBuffer;	// 맵버퍼(픽셀충돌 체크)  //충돌처리맵버퍼 
	ePlayerAime    m_eState;         //애니동작에 따라 바뀌게 하기 위해서 
	cPlayer*       m_player;
	cMap *         m_pMap;
	cCamera*       m_pCamera;
	int            m_iFrameX;        //X값에 따라 이미지 스프라이트 변경
	float          fGravity;
	bool           isRight;          //초기설정방향
	void           PlusPlayerPosX(float plus);
	void           PlusPlayerPosY(float plus);
	int            m_nCurrNo;        //현재 플래이어 넘버
	int            m_nBombNo;         //현재폭탄 넘버

public:

	
	cPlayer() {};
	~cPlayer() {};

	void Update();
	void Render();
	void Setup();
	void CheckPixel();
	void PlayerController();

	void SetMap(cMap* map) { m_pMap = map; };
	void SetCamera(cCamera* camera) { m_pCamera = camera; };


	bool GetPlayerBomb2() { if (m_nBombNo == 2) return true;
	                         else return false;}
	void SetPlayerCamera(bool nextturn);
	
};

