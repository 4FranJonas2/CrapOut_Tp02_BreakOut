#pragma once

const float screenWidth = 800.0f;
const float screenHeight = 650.0f;
const float auxFloat = 100.0f;
const float arenaMarkBoard = 100.0f;

//arena settings
const float minDistanceFromBorder = 10.0f;
const float arenaPaletteWidth = screenWidth - 2;
const float arenaPaletteHeigth = screenHeight - arenaMarkBoard;
const float arenaPosX = screenWidth/2;
const float arenaPosY = screenHeight/2;

//player settings
const float playerPaletteWidth = 80.0f;
const float playerPaletteHeigth =20.0f;
const float playerSpeed = 450.0f;
const float playerPosX = arenaPaletteWidth / 2;
const float playerPosY = arenaMarkBoard /2 + minDistanceFromBorder * 2;

//bricks settings
const int maxBriksRows = 2;
const int maxBriksCols = 10;
const float brickPaletteWidth = 60.0f;
const float brickPaletteHeigth = 20.0f;
const float brickPosX = 60.0f;
const float brickPosY = arenaPaletteHeigth ;
const int horizontalSpacing = 15; 
const int verticalSpacing = 30;


//ball settings
const float ballWidth = 15.0f;
const float ballHeigth = 15.0f;
const int ballRad = 10;
const int ballMinRange = -100.0f;
const int ballMaxRange = 100.0f;
const float ballSpeed = 400.0f;
const float maxBallXSpeed = 400.0f;
const float maxBallYSpeed = 200.0f;
const float vertices = 30.0f;
