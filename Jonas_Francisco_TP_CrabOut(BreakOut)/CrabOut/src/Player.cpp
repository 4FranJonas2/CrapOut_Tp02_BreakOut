#include "Player.h"
#include "Color.h"

namespace gamePlayer
{
	Rectangle player;
	Rectangle bricks;
	Rectangle arenaLimits;
	Color color;

	void InitPlayer()
	{
		player = CreatePlayer(player);
	}
	void InitBrick()
	{
		bricks = CreateBrick(bricks);

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
	Rectangle CreateBrick(Rectangle& bricks)
	{
		bricks.recColor = PURPLE;
		
		bricks.recDimensions.x = brickPaletteWidth;
		bricks.recDimensions.y = brickPaletteHeigth;
		bricks.recPosition.x = brickPosX;
		bricks.recPosition.y = brickPosY;

		return bricks;
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
		slRectangleFill(player.recPosition.x, player.recPosition.y,
			player.recDimensions.x,player.recDimensions.y);
	}
	void DrawArenaLimits()
	{
		slRectangleOutline(arenaLimits.recPosition.x, arenaLimits.recPosition.y,
			arenaLimits.recDimensions.x, arenaLimits.recDimensions.y);	
	}
	void DrawBrick()
	{
		slRectangleFill(bricks.recPosition.x, bricks.recPosition.y,
			bricks.recDimensions.x, bricks.recDimensions.y);
	}

	void InputPlayer(Rectangle& player)
	{
		if (SL_ALIGN_RIGHT)
		{
			player.playerDir = DIRECTION::RIGHT;
		}
		else if (SL_ALIGN_LEFT)
		{
			player.playerDir = DIRECTION::LEFT;
		}
		StopMovement(player);
	}
	void StopMovement(Rectangle& player)
	{
		if (SL_ALIGN_RIGHT && SL_ALIGN_LEFT)
		{
			player.playerDir = DIRECTION::STOP;
		}
	}
	void UpdatePlayer(Rectangle& player)
	{
		bool IsRightTopScreen = (player.recPosition.x + player.recDimensions.x) >= (screenWidth - minDistanceFromBorder);
		bool IsLeftTopScreen = player.recPosition.x <= arenaLimits.recDimensions.x + minDistanceFromBorder;

		if (player.playerDir == DIRECTION::RIGHT)
		{
			if (!IsRightTopScreen)
			{
				player.recPosition.x -= playerSpeed * slGetDeltaTime();
			}
		}
		else if (player.playerDir == DIRECTION::LEFT)
		{
			if (!IsLeftTopScreen)
			{
				player.recPosition.x += playerSpeed * slGetDeltaTime();
			}
		}
	}
}