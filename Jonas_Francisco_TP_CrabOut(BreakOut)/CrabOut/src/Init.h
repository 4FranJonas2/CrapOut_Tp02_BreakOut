#pragma once
#include "Input.h"

namespace gameInit
{
	void Init(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simMainMenuStatus);
	void InitSim();
	void ResetMenu();
	void ResetGameplay();
}