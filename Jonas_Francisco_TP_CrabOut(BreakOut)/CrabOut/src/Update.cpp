#include "Update.h"

namespace gameUpdate
{
	void Update(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus)
	{
		gamePlayer::Update();
	}
}