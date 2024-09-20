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

		while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			gameInit::Init(simStatus, simMenuStatus, simGamePlayStatus);

			gameInput::Input(simStatus, simMenuStatus, simGamePlayStatus);
			gameUpdate::Update(simStatus, simMenuStatus, simGamePlayStatus);
			drawSimulation::Draw(simStatus, simMenuStatus, simGamePlayStatus);
		}
		close();
	}

	void close()
	{
		slClose();
	}
}
