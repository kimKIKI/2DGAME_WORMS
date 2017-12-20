#pragma once

class cCamera
{
private:
	cImage*  m_ImgMapBuffer;  //�����
	cImage*  m_imgBG;         //��ü �ڹ��

	float    m_fMapPosX;     //��ī�޶���ġ
	float    m_fMapPosY;     //��ī�޶� ��ġ
	float    m_fStartPosX;   //���̵��� ���� ������ġ
	float    m_fStartPosY;   //���̵��� ���� ������ġ 
	float    m_fEndPosX;
	float    m_fEndPosY;
	float	 m_fBGPosX;		  // ��� ī�޶� ��ġ
	float	 m_fBGPosY;		  // ��� ī�޶� ��ġ
	float    m_fBefMousePosX;     //���콺 Ŭ���� ��ġ
	float    m_fBefMousePosY;     //���콺 Ŭ���� ��ġ
	float	 m_fT;             //����������
	bool	 m_isMoving;	   // ī�޶� �̵���
	bool     m_isClick;        //ī�޶�Ŭ����
	
	

public:
	cCamera();
	~cCamera();

	void Setup();
	void Update();

	
	void  SetCamera(float centerX, float centerY);
	void  MoveCamera(float centerX, float centerY);
	void  PlusPosY(float plus);
	void  PlusPosX(float plus);

	//������ ��ġ �˷���
	float  GetBGDestX() { return -m_fBGPosX; }
	float  GetBGDestY() { return -m_fBGPosY; }

	bool  GetMoveCamera() { return m_isMoving; }
	bool  GetClickMap() { return m_isClick; }

	//�ʹ��� ��� ��ġ �˷���
	float GetMapDestX() { return -m_fMapPosX; }
	float GetMapDestY() { return -m_fMapPosY; }


};

