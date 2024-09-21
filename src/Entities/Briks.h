#pragma once
#include "..\Settings\Utils.h"

namespace gameBrick
{
	struct Rectangle
	{
		Vector2 recDimensions;
		Vector2 recPosition;
		Color recColor;
	};

	Rectangle CreateBrick(Rectangle& bricks);
	void InitBrick();
	void Update();
	void DrawBrick();
}