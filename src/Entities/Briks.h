#pragma once
#include "Player.h"
namespace gameBrick
{
	struct Brick
	{
		Rectangle rec;
		Color recColor;
		bool isAlive = true;
	};


	void InitBrick();
	Brick CreateBrick(Brick& brick, int i, int j);
	void paintBrik(Color color);
	void Update();
	void DrawBrick();
}