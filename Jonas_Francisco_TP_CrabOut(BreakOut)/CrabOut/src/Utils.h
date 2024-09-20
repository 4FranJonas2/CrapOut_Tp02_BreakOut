#pragma once
#include "Color.h"
#include "sl.h"
#include "Constants.h"

enum class LOOPSTATUS
{
	NONE,
	INITSIM,
	MAINMENU,
	GAME,
	EXIT
};

enum class MAINMENUSTATUS
{
	NONE,
	PLAY,
	CREDITS,
	EXIT,
	BACK
};

enum class GAMESTATUS
{
	NONE,
	GAMEPLAY,
	GAMEPAUSE,
	GAMERESET,
	GAMERESUME,
	GAMEEND
};

struct Vector2
{
	float x;
	float y;
};

struct Ball
{
	float radius;
	Vector2 ballPosition;
	Color ballColor = RED;
};

