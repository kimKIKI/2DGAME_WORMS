#pragma once
#include "cGameNode.h"
#include "cPlayer.h"


class cPlayer;
class cMap;
class cCamera;
class cCursor;

class cWormScene:public cGameNode
{

private:
	cImage*       m_pWarm;
	cImage*       m_pImgMapBuffer;
	cImage*       m_pBackGround;
	cImage*       m_pBackGroundBMP;


	cPlayer*      m_pPlayer;
	cMap*         m_pMap;
	cCamera*      m_pCamera;
	cCursor*      m_pCursor;

public:
	cWormScene() {};
	virtual ~cWormScene() {};

	virtual void  Setup()   override;
	virtual void  Update()  override;
	virtual void  Render()  override;
	virtual void  Release() override;

};

