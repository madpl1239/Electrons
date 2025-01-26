/*
 * keyboard.hpp
 * 
 * 26-01-2025 by madpl
 */
#pragma once

#include "defines.hpp"


void increaseSpeed()
{
	speed += 0.1f;
}


void decreaseSpeed()
{
	if(speed > 0.0f)
		speed -= 0.1f;
	
	if(speed < 0.0f)
		speed = 0.0f;
}


void moveCameraUp()
{
	cameraAngleX -= 5.0f;
}


void moveCameraDown()
{
	cameraAngleX += 5.0f;
}


void moveCameraLeft()
{
	cameraAngleY -= 5.0f;
}


void moveCameraRight()
{
	cameraAngleY += 5.0f;
}


void zoomIn()
{
	cameraDistance -= 10.0f;
}


void zoomOut()
{
	cameraDistance += 10.0f;
}
