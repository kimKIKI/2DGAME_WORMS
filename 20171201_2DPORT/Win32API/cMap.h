#pragma once

class cPlayer;

class cMap
{

private:
	cImage*    m_pImgMap;
	//��ġ��� �ʹ���
	cImage*    m_pImgMapBuffer;
	cMap*      m_Map;
	cPlayer*   m_pPlayer;
	float      m_fBlastPosX;
	float      m_fBlastPosY;
	float      m_fBlastSize;
	bool       m_isBlasting; //��ź�� �浹������ �Ǵ��Ѵ�.


public:
	cMap() ;
	~cMap();

	void Setup();
	void Update();
	void Render();
	void SetPlayer(cPlayer* player) { m_pPlayer = player; };
};

