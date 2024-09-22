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

		bricks.rec.size.x = brickPaletteWidth;
		bricks.rec.size.y = brickPaletteHeigth;
		bricks.rec.pos.x = brickPosX;
		bricks.rec.pos.y = brickPosY;

		return bricks;
	}

	void Update()
	{

	}

	void DrawBrick()
	{
		slRectangleFill(bricks.rec.pos.x, bricks.rec.pos.y,
			bricks.rec.size.x, bricks.rec.size.y);
	}
}