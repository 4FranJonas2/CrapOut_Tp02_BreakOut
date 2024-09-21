#pragma once
#include "Player.h"
namespace gameBrick
{
	struct Brick
	{
		Rectangle rec;
		Color recColor;
	};

	Brick CreateBrick(Brick& bricks);
	void InitBrick();
	void Update();
	void DrawBrick();
}