#pragma once

class cCamera;
class cPlayer;

#define CURSOR_SIZE 30

class cCursor
{
private:
	cCamera*   m_pCamera;
	cPlayer*   m_pPlayer;
	cImage*    m_pImgCursor;

public:
	cCursor();
	~cCursor();

	void Setup();
	void Update();
	void Render();

	void SetCamera(cCamera* camera) { m_pCamera = camera; };
	void SetPlayer(cPlayer* player) { m_pPlayer = player; };
};

