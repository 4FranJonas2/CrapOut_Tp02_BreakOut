#include "Init.h"

namespace gameInit
{
	void init()
	{
		// set up our window and a few resources we need
		slWindow(screenWidth, screenHeight, "CrabOut by Francisco Jonas", false);
		slSetFont(slLoadFont("hHittoSushi.ttf"), 24);
		slSetTextAlign(SL_ALIGN_CENTER);
	}

}

