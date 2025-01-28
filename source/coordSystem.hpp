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
	CCoordinateSystem(float x, float y, float width, float height, float size):
		m_positionX(x),
		m_positionY(y),
		m_width(width),
		m_height(height),
		m_size(size)
	{
		// empty
	}
	
	void update(float angleX, float angleY)
	{
		m_angleX = angleX; // Kąt obrotu kamery wokół osi X
		m_angleY = angleY; // Kąt obrotu kamery wokół osi Y
	}
	
	void draw()
	{
		// Rysowanie ramki "boksa"
		drawFrame();
		
		// Ustawienie "boksa" w oknie za pomocą glViewport
		glViewport(m_positionX, m_positionY, m_width, m_height);
		
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluPerspective(45.0f, static_cast<float>(m_width) / m_height, 1.0f, 100.0f);
		
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		
		// Translacja do środka "boksa" i oddalenie
		glTranslatef(0.0f, 0.0f, -10.0f); // Środek boksa, kamera oddalona o -10 jednostek
		
		// Obrót układu współrzędnych
		glRotatef(m_angleX, 1.0f, 0.0f, 0.0f);
		glRotatef(m_angleY, 0.0f, 1.0f, 0.0f);
		
		// Rysowanie osi X (czerwona)
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(m_size, 0.0f, 0.0f);
		glEnd();
		
		// Rysowanie osi Y (zielona)
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, m_size, 0.0f);
		glEnd();
		
		// Rysowanie osi Z (niebieska)
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, m_size);
		glEnd();
		
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		
		// Przywrócenie domyślnego viewportu
		glViewport(0, 0, WIDTH, HEIGHT);
	}
	
private:
	void drawFrame()
	{
		// Przywrócenie pierwotnego viewportu, aby narysować ramkę 2D
		glViewport(0, 0, WIDTH, HEIGHT);
		
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		
		// Rysowanie ramki w 2D
		glColor3f(1.0f, 1.0f, 1.0f); // Kolor biały dla ramki
		glBegin(GL_LINE_LOOP);
		glVertex2f(m_positionX, m_positionY); // Lewy dolny róg
		glVertex2f(m_positionX + m_width, m_positionY); // Prawy dolny róg
		glVertex2f(m_positionX + m_width, m_positionY + m_height); // Prawy górny róg
		glVertex2f(m_positionX, m_positionY + m_height); // Lewy górny róg
		glEnd();
		
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
	}	
	
	float m_positionX; // Pozycja X "boksa" (lewy dolny róg)
	float m_positionY; // Pozycja Y "boksa" (lewy dolny róg)
	float m_width;     // Szerokość "boksa"
	float m_height;    // Wysokość "boksa"
	float m_size;      // Rozmiar osi układu współrzędnych
	
	float m_angleX = 0.0f; // Obrót wokół osi X
	float m_angleY = 0.0f; // Obrót wokół osi Y
};
