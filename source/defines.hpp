/*
 * defines.hpp
 * 
 * 26-01-2025 by madpl
 */
#pragma once

#define glRGB(r, g, b) glColor3f((GLfloat)r / 255.0f, (GLfloat)g / 255.0f, (GLfloat)b / 255.0f)

// window size
const int WIDTH = 800;
const int HEIGHT = 600;

GLUquadricObj *g_normalObject = nullptr;

// variable electron speed
float speed = 1.0f;

// angle of rotation around the nucleus
static float fElect1 = 0.0f;

// for support camera
float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;
float cameraDistance = 250.0f;
