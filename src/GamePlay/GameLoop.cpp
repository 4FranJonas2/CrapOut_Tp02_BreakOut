#include "GameLoop.h"
#include "iostream"

//xcopy"projectDir\res" "outdir\res"

namespace gameLoop
{
	void gameLoop()
	{
		LOOPSTATUS simStatus;
		MAINMENUSTATUS simMenuStatus;
		GAMESTATUS simGamePlayStatus;
		
		gameInit::Init(simStatus, simMenuStatus, simGamePlayStatus);

		while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			Input(simStatus, simMenuStatus, simGamePlayStatus);
			Update(simStatus, simMenuStatus, simGamePlayStatus);
			Draw(simStatus, simMenuStatus, simGamePlayStatus);
		}
		close();
	}

	void Input(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus)
	{
		gamePlayer::Input();
	}
	void Update(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus)
	{
		gamePlayer::Update();
		gameBall::Update();

		CheckColision(gamePlayer::GetPlayer(), gameBall::GetBall());
	}
	void Draw(LOOPSTATUS& simStatus, MAINMENUSTATUS& simMenuStatus, GAMESTATUS& simGamePlayStatus)
	{
		gamePlayer::DrawPlayer();
		gamePlayer::DrawArenaLimits();
		gameBrick::DrawBrick();
		gameBall::DrawBall();

		slRender();
	}


	void CheckColision(gamePlayer::Player player, gameBall::Ball ball)
	{


	}

	void close()
	{
		slClose();
	}	
}
