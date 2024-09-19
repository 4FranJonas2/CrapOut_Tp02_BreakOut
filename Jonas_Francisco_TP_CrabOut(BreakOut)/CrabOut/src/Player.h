#pragma once
#include "Utils.h"

namespace gamePlayer
{
	enum class DIRECTION
	{
		STOP = 1,
		UP,
		DOWN
	};

	struct Rectangle
	{
		Vector2 recDimensions;
		Vector2 recPosition;
		Color recColor;
		DIRECTION playerDir;
	};

	void InitPlayer();
	void InitBrick();
	void InitArena();

	Rectangle CreatePlayer(Rectangle& player);
	Rectangle CreateBrick(Rectangle& bricks);
	Rectangle CreateArena(Rectangle& arenaLimits);

	void InputPlayer();

	void UpdatePlayer();

	void DrawPlayer();
	void DrawArenaLimits();
}