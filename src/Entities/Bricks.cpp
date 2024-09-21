#include "Briks.h"

namespace gameBrick
{
	Rectangle bricks;

	void InitBrick()
	{
		bricks = CreateBrick(bricks);

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

	void Update()
	{

	}

	void DrawBrick()
	{
		slRectangleFill(bricks.recPosition.x, bricks.recPosition.y,
			bricks.recDimensions.x, bricks.recDimensions.y);
	}
}