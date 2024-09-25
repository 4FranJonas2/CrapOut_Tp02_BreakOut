#pragma once
#include "..\Settings\Utils.h"

namespace gamePlayer
{
	enum class DIRECTION
	{
		STOP = 1,
		RIGHT,
		LEFT
	};

	struct Player
	{
		Rectangle rec;
		Color recColor;
		DIRECTION playerDir;
	};

	struct Arena
	{
		Rectangle rec;
		Color recColor;
	};

	void InitPlayer();
	void InitArena();

	Player CreatePlayer(Player& player);
	Arena CreateArena(Arena& arenaLimits);
	Player GetPlayer();

	void Input();
	void Update();
	void DrawPlayer();
	void DrawArenaLimits();

	void InputPlayer(Player& player);
	void StopMovement(Player& player);
	void UpdatePlayer(Player& player);
}