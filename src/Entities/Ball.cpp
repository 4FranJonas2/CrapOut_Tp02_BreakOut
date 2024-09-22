#include "Ball.h"
#include <iostream>
#include<ctime>

namespace gameBall
{
	Ball ball;
	Rectangle rec;

	void InitBall(Rectangle rec)
	{
		ball = CreateBall(ball, rec);
	}
	Ball CreateBall(Ball& ball, Rectangle rec)
	{
		ball.ballColor = RED;
		ball.rec.size.x = ballWidth;
		ball.rec.size.y = ballHeigth;
		ball.rec.pos.x = rec.size.x;
		ball.rec.pos.y = ball.rec.size.y / 2 + rec.size.y;
		ball.radius = ballRad;

		ball.ballVectorRanges.x = ballMinRange;
		ball.ballVectorRanges.y = ballMaxRange;
		ball.isAlive = true;
		ball.ballInitlaunch = false;
		ball.ballVertices = vertices;

		return ball;
	}

	Ball GetBall()
	{
		return ball;
	}

	void Update()
	{
		//init
		GetRandInitDir(ball);

		//normal movmment
		normaliceBallVector(ball);
		CheckArenaCollision(ball);
		ChekPlayerCollision(ball, rec);
	}
	void DrawBall()
	{
		slCircleFill(ball.rec.size.x, ball.rec.size.y, ball.radius, ball.ballVertices);
	}

	static void GetRandInitDir(Ball& ball)
	{
		//set random init vector
		if (slGetKey(SL_KEY_ENTER) && !ball.ballInitlaunch)
		{
			ball.rec.pos.x = 0 + (rand() % ballMaxRange + 1);
			ball.rec.pos.y = 0 + (rand() % ballMaxRange + 1);

			normaliceBallVector(ball);

			ball.ballInitlaunch = false;
		}
	}
	void normaliceBallVector(Ball& ball)
	{
		float vectorLength = sqrt(ball.rec.pos.x * ball.rec.pos.x + ball.rec.pos.y * ball.rec.pos.y);

		if (vectorLength != 0)
		{
			ball.rec.pos.x = ball.rec.pos.x / vectorLength;
			ball.rec.pos.y = ball.rec.pos.y / vectorLength;
		}

		ball.rec.pos.x += (ball.rec.pos.x * ballSpeed) * slGetDeltaTime();
		ball.rec.pos.y += (ball.rec.pos.y * ballSpeed) * slGetDeltaTime();
	}

	void CheckArenaCollision(Ball& ball)
	{
		// Check walls collision
		bool IsRigthSide = ball.rec.pos.x >= screenWidth - minDistanceFromBorder - ball.rec.size.x;
		bool IsLeftSide = ball.rec.pos.x <= 0 + minDistanceFromBorder + ball.rec.size.x;
		bool IsTop = ball.rec.pos.y <= screenHeight + minDistanceFromBorder + ball.rec.size.y;
		bool IsBottom = ball.rec.pos.y >= 0 + minDistanceFromBorder + ball.rec.size.y;

		if (IsRigthSide)
		{
			ball.rec.pos.x = screenWidth - ball.rec.size.x - minDistanceFromBorder;
			ball.rec.pos.x *= -1.0f;
		}
		else if (IsLeftSide)
		{
			ball.rec.pos.x = 0 + ball.rec.size.x + minDistanceFromBorder;
			ball.rec.pos.x *= -1.0f;
		}

		if (IsTop)
		{
			ball.rec.pos.y = (screenHeight - ball.rec.size.y - minDistanceFromBorder);
			ball.rec.pos.y *= -1.0f;
		}
		else if (IsBottom)
		{
			ball.rec.pos.y = (0 + ball.rec.size.y + minDistanceFromBorder);
			ball.rec.pos.y *= -1.0f;
		}
	}
	void ChekPlayerCollision(Ball& ball, Rectangle player)
	{
		float minDistanceX = (player.size.x / 2) + ball.radius;
		float minDistanceY = (player.size.y / 2) + ball.radius;
		float distanceBallRecX = abs(player.pos.x - ball.rec.pos.x);
		float distanceBallRecY = abs(player.pos.y - ball.rec.pos.y);
		float penetrationX = abs(minDistanceX - distanceBallRecX);
		float penetrationY = abs(minDistanceY - distanceBallRecY);
		bool collisionIsInX = penetrationX < penetrationY;

		bool IsRigthSide = ball.rec.pos.x > player.pos.x + (player.size.x / 2);
		bool IsLeftSide = ball.rec.pos.x < player.pos.x - (player.size.x / 2);
		bool IsTop = ball.rec.pos.y < player.pos.y - (player.size.y / 2);
		bool IsBottom = ball.rec.pos.y > player.pos.y + (player.size.y / 2);

		if (collisionIsInX)
		{
			if (IsRigthSide)
			{
				ball.rec.pos.x += penetrationX;
				ball.rec.pos.x *= -1.0f;
			}
			else if (IsLeftSide)
			{
				ball.rec.pos.x -= penetrationX;
				ball.rec.pos.x *= -1.0f;
			}
		}

		else
		{
			if (IsTop)
			{
				ball.rec.pos.y -= penetrationY;
				ball.rec.pos.y *= -1.0f;
			}
			else if (IsBottom)
			{
				ball.rec.pos.y += penetrationY;
				ball.rec.pos.y *= -1.0f;
			}
		}
		/*if (distance <= ball.ballRad)
		{
		}*/
	}

	//static float IsCollision(Ball ball, gamePlayer::Rectangle player)
	//{
	//	Vector2 collisionPoint;
	//	collisionPoint.x = ball.ballPosition.x;
	//	collisionPoint.y = ball.ballPosition.y;

	//	// which edge is closest?
	//	if (ball.ballPosition.x < player.PosX)
	//		collisionPoint.x = player.PosX;      // test left edge
	//	else if (ball.ballPosition.x > player.PosX + player.playerWidth)
	//		collisionPoint.x = player.PosX + player.playerWidth;   // right edge

	//	if (ball.ballPosition.y < player.PosY)
	//		collisionPoint.y = player.PosY;      // top edge
	//	else if (ball.ballPosition.y > player.PosY + player.playerHeigth)
	//		collisionPoint.y = player.PosY + player.playerHeigth;   // bottom edge

	//	// get distance from closest edges
	//	float distX = ball.ballPosition.x - collisionPoint.x;
	//	float distY = ball.ballPosition.y - collisionPoint.y;
	//	float distance = sqrt((distX * distX) + (distY * distY));

	//	return distance;
	//}
}