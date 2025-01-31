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


void moveCamXUFunc()
{
	cameraAngleX -= 5.0f;
}


void moveCamXDFunc()
{
	cameraAngleX += 5.0f;
}


void moveCamYUFunc()
{
	cameraAngleY -= 5.0f;
}


void moveCamYDFunc()
{
	cameraAngleY += 5.0f;
}


void moveCamZUFunc()
{
	cameraAngleZ -= 5.0f;
}


void moveCamZDFunc()
{
	cameraAngleZ += 5.0f;
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
