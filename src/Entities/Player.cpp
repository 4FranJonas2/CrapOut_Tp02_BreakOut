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

		player.rec.size.x = playerPaletteWidth;
		player.rec.size.y = playerPaletteHeigth;
		player.rec.pos.x = playerPosX;
		player.rec.pos.y = playerPosY;

		return player;
	}
	Arena CreateArena(Arena& arenaLimits)
	{
		arenaLimits.recColor = RED;

		arenaLimits.rec.size.x = arenaPaletteWidth;
		arenaLimits.rec.size.y = arenaPaletteHeigth;
		arenaLimits.rec.pos.x = arenaPosX;
		arenaLimits.rec.pos.y = arenaPosY;

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
		slRectangleFill(player.rec.pos.x, player.rec.pos.y,
			player.rec.size.x,player.rec.size.y);
		slSetForeColor(WHITE.r, WHITE.g, WHITE.b, WHITE.a);
	}
	void DrawArenaLimits()
	{
		slRectangleOutline(arenaLimits.rec.pos.x, arenaLimits.rec.pos.y,
			arenaLimits.rec.size.x, arenaLimits.rec.size.y);
	}

	void InputPlayer(Player& player)
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
	void StopMovement(Player& player)
	{
		if (!slGetKey(SL_KEY_RIGHT) && !slGetKey(SL_KEY_LEFT))
		{
			player.playerDir = DIRECTION::STOP;
			player.rec.pos.x = player.rec.pos.x;
		}
	}
	void UpdatePlayer(Player& player)
	{
		bool IsRightSideScreen = (player.rec.pos.x + player.rec.size.x/2) >= (arenaPaletteWidth - minDistanceFromBorder);
		bool IsLeftSideScreen = (player.rec.pos.x - player.rec.size.x / 2) <= 0 + minDistanceFromBorder;

		if (player.playerDir == DIRECTION::RIGHT)
		{
			if (!IsRightSideScreen)
			{
				player.rec.pos.x += playerSpeed * slGetDeltaTime();
			}
		}
		if (player.playerDir == DIRECTION::LEFT)
		{
			if (!IsLeftSideScreen)
			{
				player.rec.pos.x -= playerSpeed * slGetDeltaTime();
			}
		}
	}
}