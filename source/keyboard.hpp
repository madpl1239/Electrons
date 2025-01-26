/*
 * keyboard.hpp
 * 
 * 26-01-2025 by madpl
 */
#pragma once

#include "defines.hpp"


void increaseSpeedFunc()
{
	speed += 0.1f;
}


void decreaseSpeedFunc()
{
	if(speed > 0.0f)
		speed -= 0.1f;
	
	if(speed < 0.0f)
		speed = 0.0f;
}


void moveCamUpFunc()
{
	cameraAngleX -= 5.0f;
}


void moveCamDownFunc()
{
	cameraAngleX += 5.0f;
}


void moveCamLeftFunc()
{
	cameraAngleY -= 5.0f;
}


void moveCamRightFunc()
{
	cameraAngleY += 5.0f;
}


void zoomInFunc()
{
	cameraDistance -= 10.0f;
}


void zoomOutFunc()
{
	cameraDistance += 10.0f;
}


void closeFunc()
{
	quit = true;
}
