#include "Briks.h"

namespace gameBrick
{
	Brick bricks[maxBriksRows][maxBriksCols];
	Brick brick;
	void InitBrick()
	{
		for (int i = 0; i < maxBriksRows; i++)
		{
			for (int j = 0; j < maxBriksCols; j++)
			{
				bricks[i][j] = CreateBrick(brick, i, j);
			}
		}
	}

	Brick CreateBrick(Brick& brick, int i, int j)
	{
		brick.recColor = PURPLE;
		brick.rec.pos.x = 0;
		brick.rec.pos.y = 0;

		brick.rec.size.x = brickPaletteWidth ;
		brick.rec.size.y = brickPaletteHeigth ;
		brick.rec.pos.x = brickPosX + (brickPaletteWidth + horizontalSpacing) * j;
		if (i > 0)
		{
			brick.rec.pos.y = brickPosY - (brickPaletteHeigth + verticalSpacing) * i;
		}
		else
		{
			brick.rec.pos.y = brickPosY;
		}
		return brick;
	}

	void paintBrik(Color color)
	{
		slSetForeColor(color.r, color.g, color.b, color.a);
	}

	void Update()
	{
	}

	void DrawBrick()
	{
		for (int i = 0; i < maxBriksRows; i++)
		{
			for (int j = 0; j < maxBriksCols; j++)
			{
				paintBrik(PURPLE);
				slRectangleFill(bricks[i][j].rec.pos.x, bricks[i][j].rec.pos.y,
					bricks[i][j].rec.size.x, bricks[i][j].rec.size.y);
				paintBrik(WHITE);
			}
		}
	}
}