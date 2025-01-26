/*
 * main.cpp
 *
 * Electron - pokazuje ruch elektronów wokoło
 * jądra atomu. Kod wykorzystuje SFML, OpenGL
 * i Glu. Korzysta z kwadryk.
 *
 * LANA Systems 1997.
 * 04-03-2019 ver: 0.1
 */
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

#define glRGB(r, g, b) glColor3f((GLfloat)r / 255.0f, (GLfloat)g / 255.0f, (GLfloat)b / 255.0f)

// window size
const int WIDTH = 800;
const int HEIGHT = 600;

float speed = 1.0f; // variable electron speed
GLUquadricObj *g_normalObject = nullptr;


void Initialize()
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


void Render()
{
	// angle of rotation around the nucleus
	static float fElect1 = 0.0f;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// transforming scene into observer layout
	glTranslatef(0.0f, 0.0f, -250.0f);

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

	glFlush();
}


int main(void)
{
	bool quit = false;

	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = false;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Electron 0.1 by madpl", sf::Style::Default, contextSettings);
	window.setVerticalSyncEnabled(false);

	Reshape(WIDTH, HEIGHT);
	Initialize();

	g_normalObject = (GLUquadricObj*)gluNewQuadric();

	while(window.isOpen() and not quit)
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
           		quit = true;
			
			else if(event.type == sf::Event::KeyPressed)
				if(event.key.code == sf::Keyboard::Escape or event.key.code == sf::Keyboard::Q)
					quit = true;
				
			else if(event.type == sf::Event::KeyPressed)
			{
				// electron acceleration
				if(event.key.code == sf::Keyboard::Add or event.key.code == sf::Keyboard::Equal)
					speed += 0.5f;
				
				// reducing the speed of electrons
				else if((event.key.code == sf::Keyboard::Subtract or event.key.code == sf::Keyboard::Dash) and speed > 0.5f)
					speed -= 0.5f;
			}
			
			else if(event.type == sf::Event::Resized)
				Reshape(event.size.width, event.size.height);
		}
		
		Render();
		window.display();
	}
	
	window.close();
	
	return 0;
}
