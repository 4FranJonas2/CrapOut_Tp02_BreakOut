#include "Init.h"
//#include "Player.cpp"
//#include "Player.h"

namespace gameInit
{
	void Init(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& sinMainMenuStatus)
	{
		InitSim();
		gamePlayer::InitPlayer();
		gamePlayer::InitArena();

	}

	void InitSim()
	{
		// set up our window and a few resources we need
		slWindow(screenWidth, screenHeight, "CrabOut by Francisco Jonas", false);
		slSetFont(slLoadFont("hHittoSushi.ttf"), 24);
		slSetTextAlign(SL_ALIGN_CENTER);

		

	}

	void ResetMenu()
	{

	}

	void ResetGameplay()
	{

	}

}

