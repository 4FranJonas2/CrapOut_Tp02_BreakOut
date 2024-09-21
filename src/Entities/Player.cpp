#include "Player.h"


namespace gamePlayer
{
	Player player;
	Arena arenaLimits;
	Color color;

	void InitPlayer()
	{
		player = CreatePlayer(player);
	}
	void InitArena()
	{
		arenaLimits = CreateArena(arenaLimits);
	}

	Player CreatePlayer(Player& player)
	{
		player.playerDir = DIRECTION::STOP;
		player.recColor = WHITE;

		player.rec.recDimensions.x = playerPaletteWidth;
		player.rec.recDimensions.y = playerPaletteHeigth;
		player.rec.recPosition.x = playerPosX;
		player.rec.recPosition.y = playerPosY;

		return player;
	}
	Arena CreateArena(Arena& arenaLimits)
	{
		arenaLimits.recColor = RED;

		arenaLimits.rec.recDimensions.x = arenaPaletteWidth;
		arenaLimits.rec.recDimensions.y = arenaPaletteHeigth;
		arenaLimits.rec.recPosition.x = arenaPosX;
		arenaLimits.rec.recPosition.y = arenaPosY;

		return arenaLimits;
	}

	Player GetPlayer()
	{
		return player;
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
		slRectangleFill(player.rec.recPosition.x, player.rec.recPosition.y,
			player.rec.recDimensions.x,player.rec.recDimensions.y);
		slSetForeColor(WHITE.r, WHITE.g, WHITE.b, WHITE.a);
	}
	void DrawArenaLimits()
	{
		slRectangleOutline(arenaLimits.rec.recPosition.x, arenaLimits.rec.recPosition.y,
			arenaLimits.rec.recDimensions.x, arenaLimits.rec.recDimensions.y);
	}

	void InputPlayer(Player& player)
	{
		if (slGetKey(SL_KEY_ENTER))
		{

		}

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
	void StopMovement(Player& player)
	{
		if (!slGetKey(SL_KEY_RIGHT) && !slGetKey(SL_KEY_LEFT))
		{
			player.playerDir = DIRECTION::STOP;
			player.rec.recPosition.x = player.rec.recPosition.x;
		}
	}
	void UpdatePlayer(Player& player)
	{
		bool IsRightSideScreen = (player.rec.recPosition.x + player.rec.recDimensions.x/2) >= (screenWidth - minDistanceFromBorder);
		bool IsLeftSideScreen = (player.rec.recPosition.x - player.rec.recDimensions.x / 2) <= 0 + minDistanceFromBorder;

		if (player.playerDir == DIRECTION::RIGHT)
		{
			if (!IsRightSideScreen)
			{
				player.rec.recPosition.x += playerSpeed * slGetDeltaTime();
			}
		}
		if (player.playerDir == DIRECTION::LEFT)
		{
			if (!IsLeftSideScreen)
			{
				player.rec.recPosition.x -= playerSpeed * slGetDeltaTime();
			}
		}
	}
}