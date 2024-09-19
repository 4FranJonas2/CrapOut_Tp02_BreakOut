#pragma once

const float screenWidth = 800.0f;
const float screenHeight = 650.0f;

//player settings
const float minDistanceFromBorder = 10.0f;
const float playerPaletteWidth = 80.0f;
const float playerPaletteHeigth = 15.0f;
const float playerSpeed = 450.0f;
const float playerPosX = screenWidth / 2;
const float playerPosY = playerPaletteHeigth + minDistanceFromBorder;

//bricks settings
const int maxInitBriks = 20;

//arena settings
const float arenaPaletteWidth = screenWidth - minDistanceFromBorder;
const float arenaPaletteHeigth = screenHeight - minDistanceFromBorder;
const float arenaPosX = screenWidth/2;
const float arenaPosY = screenHeight/2;