#include "GameLoop.h"
#include "iostream"

namespace gameLoop
{
	void gameLoop()
	{
		gameInit::init();

		while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			 //background glow
			slSetForeColor(0.1, 0.9, 1, 0.4);
			 //large text and fat line
			slSetForeColor(0.0, 0.8, 0.2, 1.0);
			slSetFontSize(24);
			slText(screenWidth / 2, screenHeight / 2, "CACHO:");
			slRectangleFill(200, 240, 100, 7);
			// smaller subtext
			slSetFontSize(14);
			slText(200, 220, "Sprites, text, sound, input, and more!");
			slLine(48, 210, 352, 210);
			Draw();
		}
		close();
	}

	void Draw()
	{
		slRender();
	}
	void close()
	{
		slClose();
	}
}
