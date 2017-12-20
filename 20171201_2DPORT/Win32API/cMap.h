#pragma once

class cPlayer;

class cMap
{

private:
	cImage*    m_pImgMap;
	//합치기용 맵버퍼
	cImage*    m_pImgMapBuffer;
	cMap*      m_Map;
	cPlayer*   m_pPlayer;
	float      m_fBlastPosX;
	float      m_fBlastPosY;
	float      m_fBlastSize;
	bool       m_isBlasting; //폭탄과 충돌중인지 판단한다.


public:
	cMap() ;
	~cMap();

	void Setup();
	void Update();
	void Render();
	void SetPlayer(cPlayer* player) { m_pPlayer = player; };
};

