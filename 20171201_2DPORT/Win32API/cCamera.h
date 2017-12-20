#pragma once

class cCamera
{
private:
	cImage*  m_ImgMapBuffer; //�����
	cImage*  m_imgBG;       //��ü �ڹ��
	float    m_fMapPosX;    //��ī�޶���ġ
	float    m_fMapPosY;    //��ī�޶� ��ġ
	float    m_fStartPosX;  //���̵��� ���� ������ġ
	float    m_fStartPosY;  //���̵��� ���� ������ġ 
	float    m_fEndPosX;
	float    m_fEndPosY;
	float	 m_fBGPosX;		// ��� ī�޶� ��ġ
	float	 m_fBGPosY;		// ��� ī�޶� ��ġ


	bool	 m_isMoving;	// ī�޶� �̵���
	bool     m_isClick;     //ī�޶�Ŭ����

	

public:
	cCamera();
	~cCamera();

	//�ʹ��� ��� ��ġ �˷���
	void  SetCamera(float centerX, float centerY);
	void  MoveCamera(float centerX, float centerY);

	//������ ��ġ �˷���
	float  GetBGDestX() { return -m_fBGPosX; }
	float  GetBGDestY() { return -m_fBGPosY; }

	bool  GetMoveCamera() { return m_isMoving; }
	bool  GetClickMap() { return m_isClick; }

};

