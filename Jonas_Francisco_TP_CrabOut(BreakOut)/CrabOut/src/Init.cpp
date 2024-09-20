#include "Init.h"
//#include "Player.cpp"
//#include "Player.h"

namespace gameInit
{
	void Init(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus)
	{
		InitSim(simStatus, simMenuStatus, simGamePlayStatus);
		

	}

	void InitSim(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus)
	{
		// set up our window and a few resources we need
		slWindow(screenWidth, screenHeight, "CrabOut by Francisco Jonas", false);
		slSetFont(slLoadFont("hHittoSushi.ttf"), 24);
		slSetTextAlign(SL_ALIGN_CENTER);

		//set up status gates
		simStatus = LOOPSTATUS::MAINMENU;
		simMenuStatus = MAINMENUSTATUS::NONE;
		simGamePlayStatus = GAMESTATUS::NONE;

		//set up entitys
		gamePlayer::InitPlayer();
		gamePlayer::InitArena();
		gamePlayer::InitBrick();
	}

	void ResetMenu()
	{

	}

	void ResetGameplay()
	{

	}

}

