#include "GameLoop.h"
#include "iostream"

namespace gameLoop
{
	void gameLoop()
	{
		LOOPSTATUS simStatus;
		MAINMENUSTATUS simMenuStatus;
		GAMESTATUS simMainMenuStatus;
		Ball ball;

		gameInit::Init(simStatus, simMenuStatus, simMainMenuStatus);

		while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			gameInput::Input(simStatus, simMenuStatus, simMainMenuStatus);
			gameUpdate::Update(simStatus, simMenuStatus, simMainMenuStatus);
			drawSimulation::Draw(simStatus, simMenuStatus, simMainMenuStatus);
		}
		close();
	}

	void close()
	{
		slClose();
	}
}
