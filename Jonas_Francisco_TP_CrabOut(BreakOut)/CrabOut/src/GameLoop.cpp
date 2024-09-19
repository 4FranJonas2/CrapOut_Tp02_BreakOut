#include "GameLoop.h"
#include "iostream"

namespace gameLoop
{
	void gameLoop()
	{
		LOOPSTATUS simStatus;
		MAINMENUSTATUS simMenuStatus;
		GAMESTATUS sinMainMenuStatus;


		gameInit::init();

		while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			

			drawSimulation::Draw();
		}
		close();
	}

	void close()
	{
		slClose();
	}
}
