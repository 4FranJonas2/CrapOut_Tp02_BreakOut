#pragma once

const float screenWidth = 800.0f;
const float screenHeight = 650.0f;
const float auxFloat = 100.0f;

//player settings
const float minDistanceFromBorder = 10.0f;
const float playerPaletteWidth = 80.0f;
const float playerPaletteHeigth = 15.0f;
const float playerSpeed = 450.0f;
const float playerPosX = screenWidth / 2;
const float playerPosY = playerPaletteHeigth + minDistanceFromBorder;

//bricks settings
const int maxInitBriks = 20;
const float brickPaletteWidth = 60.0f;
const float brickPaletteHeigth = 25.0f;
const float brickPosX = 60.0f;
const float brickPosY = 610.0f;

//ball settings
const float ballWidth = 15.0f;
const float ballHeigth = 15.0f;
const int ballRad = 10;
const int ballMinRange = -100.0f;
const int ballMaxRange = 100.0f;
const float ballSpeed = 500.0f;
const float maxBallXSpeed = 400.0f;
const float maxBallYSpeed = 200.0f;
const float vertices = 30.0f;

//arena settings
const float arenaPaletteWidth = screenWidth - minDistanceFromBorder;
const float arenaPaletteHeigth = screenHeight - minDistanceFromBorder;
const float arenaPosX = screenWidth/2;
const float arenaPosY = screenHeight/2;