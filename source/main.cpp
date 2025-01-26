/*
 * main.cpp
 *
 * Electron - shows the movement of electrons around the nucleus
 * of an atom. The code uses SFML, OpenGL and Glu. It uses quadrics.
 *
 * 04-03-2019 v0.1 by madpl (Bogdan Kułaga)
 */
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>
#include <iostream>
#include "input.hpp"
#include "defines.hpp"
#include "keyboard.hpp"
#include "drawing.hpp"


int main(void)
{
	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = false;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Electron 0.1 by madpl", sf::Style::Default, contextSettings);
	window.setPosition(sf::Vector2i(200, 100));
	window.setVerticalSyncEnabled(true);

	Reshape(WIDTH, HEIGHT);
	Initialize();

	g_normalObject = (GLUquadricObj*)gluNewQuadric();
	
	// register keys and functions
	keyboard.bindKbd(sf::Keyboard::Add, increaseSpeedFunc);
	keyboard.bindKbd(sf::Keyboard::Equal, increaseSpeedFunc);
	keyboard.bindKbd(sf::Keyboard::Subtract, decreaseSpeedFunc);
	keyboard.bindKbd(sf::Keyboard::Dash, decreaseSpeedFunc);
	keyboard.bindKbd(sf::Keyboard::Up, moveCamUpFunc);
	keyboard.bindKbd(sf::Keyboard::Down, moveCamDownFunc);
	keyboard.bindKbd(sf::Keyboard::Left, moveCamLeftFunc);
	keyboard.bindKbd(sf::Keyboard::Right, moveCamRightFunc);
	keyboard.bindKbd(sf::Keyboard::W, zoomInFunc);
	keyboard.bindKbd(sf::Keyboard::S, zoomOutFunc);
	keyboard.bindKbd(sf::Keyboard::Escape, closeFunc);
	keyboard.bindKbd(sf::Keyboard::Q, closeFunc);

	while(window.isOpen() and not quit)
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
           		quit = true;
			
			if(event.type == sf::Event::Resized)
				Reshape(event.size.width, event.size.height);
			
			keyboard.monitorKbd(event);
		}
		
		keyboard.handleKbd();
		Render(window);
		window.display();
	}
	
	window.close();
	
	return 0;
}
