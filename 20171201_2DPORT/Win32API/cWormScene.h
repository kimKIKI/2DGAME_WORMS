#pragma once
#include "cGameNode.h"
#include "cPlayer.h"

class cPlayer;

class cWormScene:public cGameNode
{

private:
	cImage*       m_pWarm;
	cImage*       m_pMap;
	cPlayer*      m_pPlayer;


public:
	cWormScene();
	~cWormScene();

	virtual void Setup() override;
	virtual void  Update() override;
	virtual void  Render() override;
	virtual void  Release() override;

};

