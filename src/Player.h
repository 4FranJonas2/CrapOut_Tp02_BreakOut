#pragma once
#include "Utils.h"

namespace gamePlayer
{
	enum class DIRECTION
	{
		STOP = 1,
		RIGHT,
		LEFT
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

	void Input();
	void Update();
	void DrawPlayer();
	void DrawArenaLimits();
	void DrawBrick();

	void InputPlayer(Rectangle& player);
	void StopMovement(Rectangle& player);
	void UpdatePlayer(Rectangle& player);
}