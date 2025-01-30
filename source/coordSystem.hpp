/*
 * coordinate_system.hpp
 *
 * Klasa rysująca układ współrzędnych XYZ w przestrzeni 3D 
 * w wybranym "boksie" w oknie.
 *
 * 26-01-2025 by madpl
 */
#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include "defines.hpp"


class CCoordinateSystem
{
public:
	explicit CCoordinateSystem(float size):
		m_size(size)
	{}

	void update(float angleX, float angleY)
	{
		m_angleX = angleX;
		m_angleY = angleY;
	}

	void draw()
	{
		glPushMatrix();
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		glTranslatef(0.0f, 0.0f, -20.0f);
		glRotatef(m_angleX, 1.0f, 0.0f, 0.0f);
		glRotatef(m_angleY, 0.0f, 1.0f, 0.0f);
		
		// drawing axes
		glBegin(GL_LINES);
		REDCOL; 
		glVertex3f(0, 0, 0);
		glVertex3f(m_size, 0, 0);
		
		FORESTGREENCOL;
		glVertex3f(0, 0, 0);
		glVertex3f(0, m_size, 0);
		
		BLUECOL;
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, m_size);
		glEnd();
		
		glPopMatrix();
	}

private:
	float m_size;
	float m_angleX = 0.0f;
	float m_angleY = 0.0f;
};
