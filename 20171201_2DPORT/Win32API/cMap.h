#pragma once
class cMap
{

private:
	cImage * m_pImgMap;
	cMap*    m_Map;

public:
	cMap() {};
	~cMap() {};

	void Setup();
	void Update();
	void Render();
	void SetMap(cMap* map) { m_Map = map; };
};

