#include "Draw.h"


namespace drawSimulation
{
	void Draw(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus)
	{

		initDraw();

		gamePlayer::DrawPlayer();

		slRender();
	}

	void initDraw()
	{
		gamePlayer::DrawPlayer();
		gamePlayer::DrawArenaLimits();
		gamePlayer::DrawBrick();
	}
}