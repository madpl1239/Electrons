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
		 
		// Ustawienie układu współrzędnych w prawym dolnym rogu
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluPerspective(45.0f, static_cast<float>(WIDTH) / HEIGHT, 1.0f, 600.0f);
		 
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		 
		// Przesunięcie układu współrzędnych w prawy dolny róg ekranu
		glTranslatef(3.5f, -3.0f, -10.0f); // Ustawienie w polu widzenia
		glScalef(0.5f, 0.5f, 0.5f);        // Zmniejszenie układu współrzędnych
		 
		// Obrót układu współrzędnych zgodnie z kamerą
		glRotatef(m_angleX, 1.0f, 0.0f, 0.0f);
		glRotatef(m_angleY, 0.0f, 1.0f, 0.0f);
		 
		// Rysowanie osi X (czerwona)
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f); // Czerwony
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(m_size, 0.0f, 0.0f);
		glEnd();
		 
		// Rysowanie osi Y (zielona)
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 0.0f); // Zielony
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, m_size, 0.0f);
		glEnd();
		 
		// Rysowanie osi Z (niebieska)
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f); // Niebieski
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, m_size);
		glEnd();
		 
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		 
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
	}
 
private:
	float m_size;    // długość osi
	float m_angleX;  // aktualny kąt obrotu wokół osi X
	float m_angleY;  // aktualny kąt obrotu wokół osi Y
};
