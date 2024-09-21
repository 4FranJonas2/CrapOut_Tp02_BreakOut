#pragma once
#include "Briks.h"
namespace gameBall
{
	struct Ball
	{
		Rectangle rec;

		Vector2 ballVectorRanges;
		Color ballColor = RED;
		float radius;
		int ballVertices;
		bool isAlive = false;
		bool ballInitlaunch = false;
	};

	void InitBall(Rectangle rec);
	Ball CreateBall(Ball& ball, Rectangle rec);
	Ball GetBall();

	void Update();
	void DrawBall();

	static void GetRandInitDir(Ball& ball);
	void normaliceBallVector(Ball& ball);

	void CheckArenaCollision(Ball& ball);
	void ChekPlayerCollision(Ball& ball,  Rectangle player);
}