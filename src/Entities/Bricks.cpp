#include "Briks.h"

namespace gameBrick
{
	Brick bricks;

	void InitBrick()
	{
		bricks = CreateBrick(bricks);

	}

	Brick CreateBrick(Brick& bricks)
	{
		bricks.recColor = PURPLE;

		bricks.rec.recDimensions.x = brickPaletteWidth;
		bricks.rec.recDimensions.y = brickPaletteHeigth;
		bricks.rec.recPosition.x = brickPosX;
		bricks.rec.recPosition.y = brickPosY;

		return bricks;
	}

	void Update()
	{

	}

	void DrawBrick()
	{
		slRectangleFill(bricks.rec.recPosition.x, bricks.rec.recPosition.y,
			bricks.rec.recDimensions.x, bricks.rec.recDimensions.y);
	}
}