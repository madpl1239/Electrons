/*
 * defines.hpp
 * 
 * 26-01-2025 by madpl
 */
#pragma once

#define glRGB(r, g, b) glColor3f((GLfloat)r / 255.0f, (GLfloat)g / 255.0f, (GLfloat)b / 255.0f)
#define glRGB2(r, g, b) (GLfloat)r / 255.0f, (GLfloat)g / 255.0f, (GLfloat)b / 255.0f

// colors for axes
#define REDCOL glRGB2(0xFF, 0x00, 0x00)
#define BLUECOL glRGB2(0x00, 0x00, 0xFF)
#define GREENCOL glRGB2(0x00, 0x80, 0x00)
#define LIMEGREENCOL glRGB2(0x32, 0xCD, 0x32)
#define PALEGREENCOL glRGB2(0x98, 0xFB, 0x98)
#define SEAGREENCOL glRGB2(0x2E, 0x8B, 0x57)
#define FORESTGREENCOL glRGB2(0x22, 0x8B, 0x22)
#define ORCHIDCOL glRGB2(0xDA, 0x70, 0xD6)
#define PLUMCOL glRGB2(0xDD, 0xA0, 0xDD)
#define MEDIUMPURPLECOL glRGB2(0x93, 0x70, 0xDB)
#define CORNFLOWERBLUECOL glRGB2(0x64, 0x95, 0xED)


// window size
const int WIDTH = 800;
const int HEIGHT = 600;
const float FOV = 55.0f;

GLUquadricObj *g_normalObject = nullptr;

// variable electron speed
float speed = 1.0f;

// angle of rotation around the nucleus
static float fElect1 = 0.0f;

// for support camera
float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;
float cameraAngleZ = 0.0f;
float cameraDistance = 250.0f;

// initial gauge position
const int GAUGEPOSX = 60;
const int GAUGEPOSY = 520;

// colors of gauge
const sf::Color GAUGECIRCLE(0x00, 0xff, 0xff, 0xff); // cyjan
const sf::Color GAUGECLUE(0xe3, 0x42, 0x34, 0xff); // cinober

bool quit = false;
