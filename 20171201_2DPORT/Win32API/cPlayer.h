#pragma once
class cWormScene;


#define PLAYER_MAX_COUNT 4
#define PLAYER_SIZE_X		50.0f
#define PLAYER_SIZE_Y		40.0f

struct tagPlayer {

	int      nPlayerNo;
	int      isRight;
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
	cImage*		  m_pImgMapBuffer;	// 맵버퍼(픽셀충돌 체크)  //충돌처리맵버퍼 
	ePlayerAime    m_eState;         //애니동작에 따라 바뀌게 하기 위해서 
	int            m_iFrameX;        //X값에 따라 이미지 스프라이트 변경
	float          fGravity;
	bool           isRight;          //초기설정방향
	void PlusPlayerPosX(float plus);
	void PlusPlayerPosY(float plus);


public:

	
	cPlayer() {};
	~cPlayer() {};

	void Update();
	void Render();
	void Setup();

	void CheckPixel();

	void PlayerController();
};

