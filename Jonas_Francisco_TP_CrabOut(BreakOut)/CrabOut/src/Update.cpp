#include "Update.h"

namespace gameUpdate
{
	void Update(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& sinMainMenuStatus)
	{
		gamePlayer::UpdatePlayer();
	}
}