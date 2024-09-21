#include "Player.h"


namespace gamePlayer
{
	Rectangle player;
	Rectangle arenaLimits;
	Color color;

	void InitPlayer()
	{
		player = CreatePlayer(player);
	}
	void InitArena()
	{
		arenaLimits = CreateArena(arenaLimits);
	}

	Rectangle CreatePlayer(Rectangle& player)
	{
		player.playerDir = DIRECTION::STOP;
		player.recColor = WHITE;

		player.recDimensions.x = playerPaletteWidth;
		player.recDimensions.y = playerPaletteHeigth;
		player.recPosition.x = playerPosX;
		player.recPosition.y = playerPosY;

		return player;
	}
	Rectangle CreateArena(Rectangle& arenaLimits)
	{
		arenaLimits.recColor = RED;

		arenaLimits.recDimensions.x = arenaPaletteWidth;
		arenaLimits.recDimensions.y = arenaPaletteHeigth;
		arenaLimits.recPosition.x = arenaPosX;
		arenaLimits.recPosition.y = arenaPosY;

		return arenaLimits;
	}

	void Input()
	{
		InputPlayer(player);
	}
	void Update()
	{
		UpdatePlayer(player);
	}
	void DrawPlayer()
	{
		slSetForeColor(RED.r, RED.g, RED.b, RED.a);
		slRectangleFill(player.recPosition.x, player.recPosition.y,
			player.recDimensions.x,player.recDimensions.y);
		slSetForeColor(WHITE.r, WHITE.g, WHITE.b, WHITE.a);
	}
	void DrawArenaLimits()
	{
		slRectangleOutline(arenaLimits.recPosition.x, arenaLimits.recPosition.y,
			arenaLimits.recDimensions.x, arenaLimits.recDimensions.y);	
	}

	void InputPlayer(Rectangle& player)
	{
		if (slGetKey(SL_KEY_RIGHT))
		{
			player.playerDir = DIRECTION::RIGHT;
		}
		if (slGetKey(SL_KEY_LEFT))
		{
			player.playerDir = DIRECTION::LEFT;
		}

		StopMovement(player);
	}
	void StopMovement(Rectangle& player)
	{
		if (!slGetKey(SL_KEY_RIGHT) && !slGetKey(SL_KEY_LEFT))
		{
			player.playerDir = DIRECTION::STOP;
			player.recPosition.x = player.recPosition.x;
		}
	}
	void UpdatePlayer(Rectangle& player)
	{
		bool IsRightSideScreen = (player.recPosition.x + player.recDimensions.x/2) >= (screenWidth - minDistanceFromBorder);
		bool IsLeftSideScreen = (player.recPosition.x - player.recDimensions.x / 2) <= 0 + minDistanceFromBorder;

		if (player.playerDir == DIRECTION::RIGHT)
		{
			if (!IsRightSideScreen)
			{
				player.recPosition.x += playerSpeed * slGetDeltaTime();
			}
		}
		if (player.playerDir == DIRECTION::LEFT)
		{
			if (!IsLeftSideScreen)
			{
				player.recPosition.x -= playerSpeed * slGetDeltaTime();
			}
		}
	}
}