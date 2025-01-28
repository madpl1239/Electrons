/*
 * drawing.hpp
 * 
 * 26-01-2025 by madpl
 */
#pragma once

#include <SFML/Graphics.hpp>
#include "defines.hpp"
#include "gauge.hpp"
#include "coordSystem.hpp"


void Initialize(void)
{
	float ambientLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// enable light model
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	
	// enable material property
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
}


void Reshape(int w, int h)
{
	GLfloat fAspect = 0.0f;
	
	if(h == 0)
		h = 1;
	
	fAspect = (GLfloat)w / (GLfloat)h;
	
	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(45.0f, fAspect, 1.0f, 600.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void drawScene(void)
{
	// red core and its drawing
	glRGB(185, 0, 0);
	gluSphere(g_normalObject, 10.0f, 8, 5);
	
	// yellow electrons
	glRGB(155, 155, 0);
	// orbit the first electron
	glPushMatrix();
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(90.0f, 0.0f, 0.0f);
	
	// drawing this electron
	gluSphere(g_normalObject, 3.0f, 8, 5);
	glPopMatrix();
	
	// orbit the second electron
	glPushMatrix();
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(-70.0f, 0.0f, 0.0f);
	
	// drawing this electron
	gluSphere(g_normalObject, 3.0f, 8, 5);
	glPopMatrix();
	
	// orbit third electron
	glPushMatrix();
	glRotatef(315.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 60.0f);
	
	// drawing this electron
	gluSphere(g_normalObject, 3.0f, 8, 5);
	glPopMatrix();
	
	fElect1 += speed;
	if(fElect1 > 360.0f)
		fElect1 = 0.0f;
}


void Render(sf::RenderWindow& window, CRotatingGauge& gauge, CCoordinateSystem& coords)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// transforming scene into observer layout
	glTranslatef(0.0f, 0.0f, -cameraDistance);
	glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
	glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);
	
	drawScene();
	
	coords.update(cameraAngleX, cameraAngleY);
	coords.draw();
	
	// drawing speed gauge
	window.pushGLStates();
	gauge.draw(window, speed, 5.0f);
	window.popGLStates();
	
	glFlush();
}
