#pragma once
#include "Briks.h"
namespace gameBall
{
	struct Ball
	{
		Rectangle rec;

		Vector2 ballDir;
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

	static void GetRandInitDir(Ball& ball);
	void InitLaunchBall(Ball& ball);
	void moveBall(Ball& ball);

	void CheckArenaCollision(Ball& ball);
	float IsCollision(Ball ball, Rectangle rec);
	void ChekRecCollision(Ball& ball,  Rectangle player);

	void Input();
	void Update(Rectangle player, Rectangle brick);
	void DrawBall(Rectangle rec);
}