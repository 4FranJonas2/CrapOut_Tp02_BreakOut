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
		ball.rec.pos.x = rec.pos.x;
		ball.rec.pos.y = rec.pos.y + rec.size.y / 2 + ball.radius + 30;
		ball.ballDir.x = 0.0f;
		ball.ballDir.y = 0.0f;
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

	static void GetRandInitDir(Ball& ball)
	{
		//set random init vector
		if (slGetKey(SL_KEY_ENTER) && !ball.ballInitlaunch)
		{
			ball.ballDir.x = ((rand() % ballMaxRange + 1)) / 100.0f;
			ball.ballDir.y = ((rand() % ballMaxRange + 1)) / 100.0f;

			moveBall(ball);

			ball.ballInitlaunch = true;
		}
	}
	void InitLaunchBall(Ball& ball)
	{
		if (slGetKey(SL_KEY_ENTER))
		{
			GetRandInitDir(ball);
		}
	}
	void moveBall(Ball& ball)
	{
		float vectorLength = sqrt(ball.ballDir.x * ball.ballDir.x + ball.ballDir.y * ball.ballDir.y);

		if (vectorLength != 0)
		{
			ball.ballDir.x = ball.ballDir.x / vectorLength;
			ball.ballDir.y = ball.ballDir.y / vectorLength;
		}

		ball.rec.pos.x += (ball.ballDir.x * ballSpeed) * slGetDeltaTime();
		ball.rec.pos.y += (ball.ballDir.y * ballSpeed) * slGetDeltaTime();
	}
	void CheckArenaCollision(Ball& ball)
	{
		// Check walls collision
		bool IsRigthSide = ball.rec.pos.x >= screenWidth - (minDistanceFromBorder + ball.radius);
		bool IsLeftSide = ball.rec.pos.x <= minDistanceFromBorder + ball.radius;
		bool IsTop = ball.rec.pos.y >= screenHeight - (minDistanceFromBorder + ball.radius);
		bool IsBottom = ball.rec.pos.y <= minDistanceFromBorder + ball.radius;

		if (IsRigthSide)
		{
			ball.rec.pos.x = screenWidth - ball.radius - minDistanceFromBorder;
			ball.ballDir.x *= -1.0f;
		}
		else if (IsLeftSide)
		{
			ball.rec.pos.x = ball.radius + minDistanceFromBorder;
			ball.ballDir.x *= -1.0f;
		}

		if (IsTop)
		{
			ball.rec.pos.y = (screenHeight - ball.radius - minDistanceFromBorder);
			ball.ballDir.y *= -1.0f;
		}
		else if (IsBottom)
		{
			ball.rec.pos.y = (ball.radius + minDistanceFromBorder);
			ball.ballDir.y *= -1.0f;
		}
	}

	float IsCollision(Ball ball, Rectangle rec)
	{
		Vector2 collisionPoint;
		collisionPoint.x = ball.rec.pos.x;
		collisionPoint.y = ball.rec.pos.y;

		// which edge is closest?
		if (ball.rec.pos.x < rec.pos.x - (rec.size.x / 2))
			collisionPoint.x = rec.pos.x - (rec.size.x / 2);      // test left edge
		if (ball.rec.pos.x > rec.pos.x + (rec.size.x / 2))
			collisionPoint.x = rec.pos.x + (rec.size.x / 2);   // right edge

		if (ball.rec.pos.y < rec.pos.y - (rec.size.y / 2))
			collisionPoint.y = rec.pos.y - (rec.size.y / 2);      // top edge
		if (ball.rec.pos.y > rec.pos.y + (rec.size.y / 2))
			collisionPoint.y = rec.pos.y + (rec.size.y / 2);   // bottom edge

		// get distance from closest edges
		float distX = ball.rec.pos.x - collisionPoint.x;
		float distY = ball.rec.pos.y - collisionPoint.y;
		float distance = sqrt((distX * distX) + (distY * distY));

		return distance;
	}

	void ChekRecCollision(Ball& ball, Rectangle player)
	{
		//if (ball.rec.pos.x + ball.rec.size.x / 2 >= player.pos.x &&     // r1 right edge past r2 left
		//	ball.rec.pos.y <= player.pos.y + player.size.y / 2 &&       // r1 left edge past r2 right
		//	ball.rec.pos.x <= player.pos.x + player.size.x / 2 &&       // r1 top edge past r2 bottom
		//	ball.rec.pos.y + ball.rec.size.y / 2 >= player.pos.y)
		//{       // r1 bottom edge past r2 top
		//	ball.ballDir.x *= -1.0f;
		//	ball.ballDir.y *= -1.0f;	
		//}
		//// are the sides of one rectangle touching the other?
		//if (ball.rec.pos.x + ball.rec.size.x/2 >= player.pos.x)
		//{
		//	// r1 right edge past r2 left
		//}
		//if (ball.rec.pos.y <= player.pos.y + player.size.y/2)
		//{
		//	// r1 bottom edge past r2 top
		//}
		//if (ball.rec.pos.x <= player.pos.x + player.size.x/2)
		//{
		//	// r1 left edge past r2 right
		//	ball.ballDir.x *= -1.0f;
		//}
		//if (ball.rec.pos.y + ball.rec.size.y/2 >= player.pos.y)
		//{
		//	// r1 top edge past r2 bottom
		//	ball.ballDir.y *= -1.0f;
		//}

		float distance = IsCollision(ball, player);
		float minDistanceX = (player.size.x / 2) + ball.radius;
		float minDistanceY = (player.size.y / 2) + ball.radius;
		float distanceBallRecX = (player.pos.x - ball.rec.pos.x);
		float distanceBallRecY = (player.pos.y - ball.rec.pos.y);
		float penetrationX = minDistanceX - abs(distanceBallRecX);
		float penetrationY = minDistanceY - abs(distanceBallRecY);
		bool collisionIsInX = penetrationX < penetrationY;

		if (distance < ball.radius)
		{
			if (penetrationY > penetrationX)
			{
				bool isPositiveDif = distanceBallRecX > 0;
				float auxDir = 0.0f;
				if (isPositiveDif)
				{
					auxDir = 1.0f;
				}
				else
				{
					auxDir = -1.0f;
				}

				ball.rec.pos.x += penetrationX * auxDir;
				ball.ballDir.x *= -1.0f;

			}
			else
			{
				bool isPositiveDif = distanceBallRecY > 0;
				float auxDir = 0.0f;
				if (isPositiveDif)
				{
					auxDir = 1.0f;
				}
				else
				{
					auxDir = -1.0f;
				}

				ball.rec.pos.y += penetrationY * auxDir;
				ball.ballDir.y *= -1.0f;
			}

		}
	}

	void Input()
	{
		InitLaunchBall(ball);
	}
	void Update(Rectangle player, Rectangle brick)
	{
		//init
		//GetRandInitDir(ball);
		//normal movmment
		moveBall(ball);
		CheckArenaCollision(ball);
		ChekRecCollision(ball, player);
		//ChekRecCollision(ball, brick);
	}
	void DrawBall(Rectangle rec)
	{
		if (!ball.ballInitlaunch)
		{
			slCircleFill(rec.pos.x, rec.pos.y + rec.size.y / 2 + ball.radius, ball.radius, ball.ballVertices);
		}
		else
		{
			slCircleFill(ball.rec.pos.x, ball.rec.pos.y, ball.radius, ball.ballVertices);
		}
	}

}

