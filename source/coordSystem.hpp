/*
 * coordSystem.hpp
 *
 * Klasa rysująca układ współrzędnych XYZ w przestrzeni 3D 
 * w prawym dolnym rogu.
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
	{
		// empty
	}

	void update(float angleX, float angleY)
	{
		m_angleX = angleX;
		m_angleY = angleY;
	}
	 
	void draw()
	{
		glPushMatrix();
		 
		// Umieszczenie układu w prawym dolnym rogu i pomniejszenie
		glTranslatef(WIDTH - 100.0f, -(HEIGHT - 100.0f), -cameraDistance);
		glScalef(0.1f, 0.1f, 0.1f); // Zmniejszenie układu współrzędnych
		glRotatef(m_angleX, 1.0f, 0.0f, 0.0f); // Obrót zgodnie z kamerą (X)
		glRotatef(m_angleY, 0.0f, 1.0f, 0.0f); // Obrót zgodnie z kamerą (Y)
		 
		// Rysowanie osi X (czerwona)
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f); // reed
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(m_size, 0.0f, 0.0f);
		glEnd();
		 
		// Rysowanie osi Y (zielona)
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 0.0f); // green
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, m_size, 0.0f);
		glEnd();
		 
		// Rysowanie osi Z (niebieska)
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f); // blue
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, m_size);
		glEnd();
		 
		glPopMatrix();
	}
 
private:
	float m_size;    // długość osi
	float m_angleX;  // aktualny kąt obrotu wokół osi X
	float m_angleY;  // aktualny kąt obrotu wokół osi Y
};
