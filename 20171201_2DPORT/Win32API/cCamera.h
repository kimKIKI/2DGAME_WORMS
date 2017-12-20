#pragma once

class cCamera
{
private:
	cImage*  m_ImgMapBuffer;  //빈버퍼
	cImage*  m_imgBG;         //전체 뒤배경

	float    m_fMapPosX;     //맵카메라위치
	float    m_fMapPosY;     //맵카메라 위치
	float    m_fStartPosX;   //맵이동시 시작 시작위치
	float    m_fStartPosY;   //맵이동시 시작 시작위치 
	float    m_fEndPosX;
	float    m_fEndPosY;
	float	 m_fBGPosX;		  // 배경 카메라 위치
	float	 m_fBGPosY;		  // 배경 카메라 위치
	float    m_fBefMousePosX;     //마우스 클릭시 위치
	float    m_fBefMousePosY;     //마우스 클릭시 위치
	float	 m_fT;             //선형보간율
	bool	 m_isMoving;	   // 카메라 이동중
	bool     m_isClick;        //카메라클릭중
	
	

public:
	cCamera();
	~cCamera();

	void Setup();
	void Update();

	
	void  SetCamera(float centerX, float centerY);
	void  MoveCamera(float centerX, float centerY);
	void  PlusPosY(float plus);
	void  PlusPosX(float plus);

	//배경출력 위치 알려줌
	float  GetBGDestX() { return -m_fBGPosX; }
	float  GetBGDestY() { return -m_fBGPosY; }

	bool  GetMoveCamera() { return m_isMoving; }
	bool  GetClickMap() { return m_isClick; }

	//맵버퍼 출력 위치 알려줌
	float GetMapDestX() { return -m_fMapPosX; }
	float GetMapDestY() { return -m_fMapPosY; }


};

