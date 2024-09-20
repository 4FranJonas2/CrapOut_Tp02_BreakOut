#include "GameLoop.h"
#include "iostream"

namespace gameLoop
{
	void gameLoop()
	{
		LOOPSTATUS simStatus;
		MAINMENUSTATUS simMenuStatus;
		GAMESTATUS simGamePlayStatus;
		Ball ball;
		gameInit::Init(simStatus, simMenuStatus, simGamePlayStatus);

		while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			gameInput::Input(simStatus, simMenuStatus, simGamePlayStatus);
			gameUpdate::Update(simStatus, simMenuStatus, simGamePlayStatus);
			gameDraw::Draw(simStatus, simMenuStatus, simGamePlayStatus);
		}
		close();
	}

	void close()
	{
		slClose();
	}
}
