#include "Ball.h"
#include <iostream>
#include<ctime>

namespace gameBall
{
	Ball ball;
	Rectangle player;

	void InitBall(Rectangle rec)
	{
		ball = CreateBall(ball, rec);
	}
	Ball CreateBall(Ball& ball, Rectangle rec)
	{
		ball.ballColor = RED;
		ball.rec.recDimensions.x = ballWidth;
		ball.rec.recDimensions.y = ballHeigth;
		ball.rec.recPosition.x = rec.recDimensions.x;
		ball.rec.recPosition.y = ball.rec.recDimensions.y / 2 + rec.recDimensions.y;
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
		ChekPlayerCollision(ball, player);
	}
	void DrawBall()
	{
		slCircleFill(ball.rec.recDimensions.x, ball.rec.recDimensions.y, ball.radius, ball.ballVertices);
	}

	static void GetRandInitDir(Ball& ball)
	{
		//set random init vector
		if (slGetKey(SL_KEY_ENTER) && !ball.ballInitlaunch)
		{
			ball.rec.recPosition.x = 0 + (rand() % ballMaxRange + 1);
			ball.rec.recPosition.y = 0 + (rand() % ballMaxRange + 1);

			normaliceBallVector(ball);

			ball.ballInitlaunch = false;
		}
	}
	void normaliceBallVector(Ball& ball)
	{
		float vectorLength = sqrt(ball.rec.recPosition.x * ball.rec.recPosition.x + ball.rec.recPosition.y * ball.rec.recPosition.y);

		if (vectorLength != 0)
		{
			ball.rec.recPosition.x = ball.rec.recPosition.x / vectorLength;
			ball.rec.recPosition.y = ball.rec.recPosition.y / vectorLength;
		}

		ball.rec.recPosition.x += (ball.rec.recPosition.x * ballSpeed) * slGetDeltaTime();
		ball.rec.recPosition.y += (ball.rec.recPosition.y * ballSpeed) * slGetDeltaTime();
	}

	void CheckArenaCollision(Ball& ball)
	{
		// Check walls collision
		bool IsRigthSide = ball.rec.recPosition.x >= screenWidth - minDistanceFromBorder - ball.rec.recDimensions.x;
		bool IsLeftSide = ball.rec.recPosition.x <= 0 + minDistanceFromBorder + ball.rec.recDimensions.x;
		bool IsTop = ball.rec.recPosition.y <= screenHeight + minDistanceFromBorder + ball.rec.recDimensions.y;
		bool IsBottom = ball.rec.recPosition.y >= 0 + minDistanceFromBorder + ball.rec.recDimensions.y;

		if (IsRigthSide)
		{
			ball.rec.recPosition.x = screenWidth - ball.rec.recDimensions.x - minDistanceFromBorder;
			ball.rec.recPosition.x *= -1.0f;
		}
		else if (IsLeftSide)
		{
			ball.rec.recPosition.x = 0 + ball.rec.recDimensions.x + minDistanceFromBorder;
			ball.rec.recPosition.x *= -1.0f;
		}

		if (IsTop)
		{
			ball.rec.recPosition.y = (screenHeight - ball.rec.recDimensions.y - minDistanceFromBorder);
			ball.rec.recPosition.y *= -1.0f;
		}
		else if (IsBottom)
		{
			ball.rec.recPosition.y = (0 + ball.rec.recDimensions.y + minDistanceFromBorder);
			ball.rec.recPosition.y *= -1.0f;
		}
	}
	void ChekPlayerCollision(Ball& ball, Rectangle player)
	{
		float minDistanceX = (player.recDimensions.x / 2) + ball.radius;
		float minDistanceY = (player.recDimensions.y / 2) + ball.radius;
		float distanceBallRecX = abs(player.recPosition.x - ball.rec.recPosition.x);
		float distanceBallRecY = abs(player.recPosition.y - ball.rec.recPosition.y);
		float penetrationX = abs(minDistanceX - distanceBallRecX);
		float penetrationY = abs(minDistanceY - distanceBallRecY);
		bool collisionIsInX = penetrationX < penetrationY;

		bool IsRigthSide = ball.rec.recPosition.x > player.recPosition.x + (player.recDimensions.x / 2);
		bool IsLeftSide = ball.rec.recPosition.x < player.recPosition.x - (player.recDimensions.x / 2);
		bool IsTop = ball.rec.recPosition.y < player.recPosition.y - (player.recDimensions.y / 2);
		bool IsBottom = ball.rec.recPosition.y > player.recPosition.y + (player.recDimensions.y / 2);

		if (collisionIsInX)
		{
			if (IsRigthSide)
			{
				ball.rec.recPosition.x += penetrationX;
				ball.rec.recPosition.x *= -1.0f;
			}
			else if (IsLeftSide)
			{
				ball.rec.recPosition.x -= penetrationX;
				ball.rec.recPosition.x *= -1.0f;
			}
		}

		else
		{
			if (IsTop)
			{
				ball.rec.recPosition.y -= penetrationY;
				ball.rec.recPosition.y *= -1.0f;
			}
			else if (IsBottom)
			{
				ball.rec.recPosition.y += penetrationY;
				ball.rec.recPosition.y *= -1.0f;
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