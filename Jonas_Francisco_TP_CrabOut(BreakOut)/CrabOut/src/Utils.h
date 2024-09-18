#pragma once
#include "Color.h"
#include "sl.h"
#include "Constants.h"

enum class LOOPSTATUS
{
	NONE = 1,
	INITSIM,
	MAINMENU,
	GAME,
	EXIT
};

enum class MAINMENUSTATUS
{
	PLAY = 1,
	CREDITS,
	EXIT,
	BACK
};

enum class GAMESTATUS
{
	GAMEPLAY = 1,
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

struct Rectangle
{
	Vector2 recDimensions;
	Vector2 recPosition;
	Color recColor = WHITE;
};

struct Ball
{
	float radius;
	Vector2 ballPosition;
	Color ballColor = RED;
};