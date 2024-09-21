#pragma once
#include "Init.h"

namespace gameLoop
{
	void gameLoop();
	void Input(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus);
	void Update(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus);
	void Draw(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus);
	void CheckColision(gamePlayer::Player player, gameBall::Ball ball);
	void close();
}