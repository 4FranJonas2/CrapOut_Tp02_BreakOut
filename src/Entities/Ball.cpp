#include "Ball.h"
#include <iostream>
#include<ctime>

namespace gameBall
{
	Ball ball;

	void InitBall()
	{
		ball = CreateBall(ball);
	}

	Ball CreateBall(Ball& ball)
	{


	}

	static void GetRandInitDir(Ball& ball)
	{
		//set random init vector
		if (slGetKey(SL_KEY_ENTER) && !ball.ballInitlaunch)
		{
			ball.ballPosition.x = ballMinRange + (rand() % ballMaxRange + 1);
			ball.ballPosition.y = ballMinRange + (rand() % ballMaxRange + 1);

			MoveBall(ball);

			ball.ballInitlaunch = false;
		}
	}

	void MoveBall(Ball& ball)
	{
		float length = sqrt(ball.ballPosition.x * ball.ballPosition.x + ball.ballPosition.y * ball.ballPosition.y);

		if (length != 0)
		{
			ball.ballPosition.x = ball.ballPosition.x / length;
			ball.ballPosition.y = ball.ballPosition.y / length;
		}

		ball.ballPosition.x += (ball.ballPosition.x * ballSpeed) * slGetDeltaTime();
		ball.ballPosition.y += (ball.ballPosition.y * ballSpeed) * slGetDeltaTime();
	}

	void CheckWallCollision(Ball& ball, float width, float heigth, float lineThick, player::Player& player1, player::Player& player2)
	{
		// Check walls collision
		bool IsRigthSide = ball.ballPosition.x >= (width - (ball.ballRad + lineThick));
		bool IsLeftSide = ball.ballPosition.x <= (ball.ballRad + lineThick);
		bool IsTop = ball.ballPosition.y <= (gameArena.y + ball.ballRad + lineThick);
		bool IsBottom = ball.ballPosition.y >= (heigth - (ball.ballRad + lineThick));

		if (IsRigthSide)
		{
			ball.ballPosition.x = (width - (ball.ballRad + lineThick));
			ball.ballDir.x *= -1.0f;
			player::AddPointPlayer1(player1);
		}
		else if (IsLeftSide)
		{
			ball.ballPosition.x = (ball.ballRad + lineThick);
			ball.ballDir.x *= -1.0f;
			player::AddPointPlayer2(player2);
		}

		if (IsTop)
		{
			ball.ballPosition.y = (gameArena.y + ball.ballRad + lineThick);
			ball.ballDir.y *= -1.0f;
		}
		else if (IsBottom)
		{
			ball.ballPosition.y = (heigth - (ball.ballRad + lineThick));
			ball.ballDir.y *= -1.0f;
		}
	}

	static float IsCollision(Ball ball, player::Player player)
	{
		Vector2 collisionPoint;
		collisionPoint.x = ball.ballPosition.x;
		collisionPoint.y = ball.ballPosition.y;

		// which edge is closest?
		if (ball.ballPosition.x < player.PosX)
			collisionPoint.x = player.PosX;      // test left edge
		else if (ball.ballPosition.x > player.PosX + player.playerWidth)
			collisionPoint.x = player.PosX + player.playerWidth;   // right edge

		if (ball.ballPosition.y < player.PosY)
			collisionPoint.y = player.PosY;      // top edge
		else if (ball.ballPosition.y > player.PosY + player.playerHeigth)
			collisionPoint.y = player.PosY + player.playerHeigth;   // bottom edge

		// get distance from closest edges
		float distX = ball.ballPosition.x - collisionPoint.x;
		float distY = ball.ballPosition.y - collisionPoint.y;
		float distance = sqrt((distX * distX) + (distY * distY));

		return distance;
	}

	void ChekPlayerCollision(Ball& ball, player::Player& player)
	{
		float distance = IsCollision(ball, player);

		float minDistanceX = (player.playerWidth / 2) + ball.ballRad;
		float minDistanceY = (player.playerHeigth / 2) + ball.ballRad;

		float distanceBallRecX = abs(player.centerPointX - ball.ballPosition.x);
		float distanceBallRecY = abs(player.centerPointY - ball.ballPosition.y);

		float penetrationX = abs(minDistanceX - distanceBallRecX);
		float penetrationY = abs(minDistanceY - distanceBallRecY);

		bool collisionIsInX = penetrationX < penetrationY;

		// if the distance is less than the radius, collision!
		if (distance <= ball.ballRad)
		{
			//CheckWallCollision(ball, player.playerWidth, player.playerHeigth, 0.0f);
			bool IsRigthSide = ball.ballPosition.x > player.centerPointX + (player.playerWidth / 2);
			bool IsLeftSide = ball.ballPosition.x < player.centerPointX - (player.playerWidth / 2);
			bool IsTop = ball.ballPosition.y < player.centerPointY - (player.playerHeigth / 2);
			bool IsBottom = ball.ballPosition.y > player.centerPointY + (player.playerHeigth / 2);

			if (collisionIsInX)
			{
				if (IsRigthSide)
				{
					ball.ballPosition.x += penetrationX;
					ball.ballDir.x *= -1.0f;
				}
				else if (IsLeftSide)
				{
					ball.ballPosition.x -= penetrationX;
					ball.ballDir.x *= -1.0f;
				}
			}

			else
			{
				if (IsTop)
				{
					ball.ballPosition.y -= penetrationY;
					ball.ballDir.y *= -1.0f;
				}
				else if (IsBottom)
				{
					ball.ballPosition.y += penetrationY;
					ball.ballDir.y *= -1.0f;
				}
			}
		}
	}

	void UpdateBall(Ball& ball, player::Player& player1, player::Player& player2)
	{
		//init
		GetRandInitPos(ball);

		//normal movmment
		MoveBall(ball);
		CheckWallCollision(ball, screenWidth, screenHeigth, lineThick, player1, player2);
		ChekPlayerCollision(ball, player1);
		ChekPlayerCollision(ball, player2);
	}

	void DrawBall(Ball ball)
	{
		DrawCircleV(ball.ballPosition, (float)ball.ballRad, MAROON);
	}

}