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
	float    fprobeX3; //�����߰�
	float    fprobeY3;  
	float    fprobeX4; //�������߰�
	float    fprobeY4;
	float    fprobeX5; //���ʾƷ�
	float    fprobeY5; 
	float    fprobeX6; //�����ʾƷ�
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
		player_Idle,			// �� ��Ʈ�� �ε�
		player_Walk,			// ���Ϸ� �ε�
		player_Atk,
		player_Aiming,          //�ܳ��ϴ�.
		player_Die,
		player_End,


	};

	tagPlayer      m_Player[PLAYER_MAX_COUNT];
	RECT 	       m_rtPlayer;
	cImage*        m_pImgPlayer;      //warm �̹���
	cImage*		  m_pImgMapBuffer;	// �ʹ���(�ȼ��浹 üũ)  //�浹ó���ʹ��� 
	ePlayerAime    m_eState;         //�ִϵ��ۿ� ���� �ٲ�� �ϱ� ���ؼ� 
	int            m_iFrameX;        //X���� ���� �̹��� ��������Ʈ ����
	float          fGravity;
	bool           isRight;          //�ʱ⼳������
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

