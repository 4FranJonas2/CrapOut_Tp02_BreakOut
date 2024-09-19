#include "Player.h"
#include "Color.h"

namespace gamePlayer
{
	Rectangle player;
	Rectangle bricks;
	Rectangle arenaLimits;

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

	void InputPlayer()
	{

	}

	void UpdatePlayer()
	{

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
}