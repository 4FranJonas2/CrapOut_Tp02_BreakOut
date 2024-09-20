#pragma once
#include "Menu.h"

namespace gameInit
{
	void Init(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus);
	void InitSim(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus);
	void ResetMenu();
	void ResetGameplay();
}