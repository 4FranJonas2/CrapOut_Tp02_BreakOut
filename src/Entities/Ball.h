#pragma once
#include "Player.h"

namespace gameBall
{
	struct Ball
	{
		float radius;
		Vector2 ballPosition;
		Color ballColor = RED;
		bool isAlive = false;
		bool ballInitlaunch = false;
	};

	void InitBall();
	Ball CreateBall(Ball& ball);
	static void GetRandInitPos(Ball& ball);

}