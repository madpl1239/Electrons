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
#include <iostream>
#include "input.hpp"
#include "defines.hpp"
#include "keyboard.hpp"
#include "drawing.hpp"


int main(void)
{
	bool quit = false;

	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = false;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Electron 0.1 by madpl", sf::Style::Default, contextSettings);
	window.setVerticalSyncEnabled(true);

	Reshape(WIDTH, HEIGHT);
	Initialize();

	g_normalObject = (GLUquadricObj*)gluNewQuadric();
	
	// register keys and functions
	keyboard.bindKbd(sf::Keyboard::Add, increaseSpeed);
	keyboard.bindKbd(sf::Keyboard::Equal, increaseSpeed);
	keyboard.bindKbd(sf::Keyboard::Subtract, decreaseSpeed);
	keyboard.bindKbd(sf::Keyboard::Dash, decreaseSpeed);
	keyboard.bindKbd(sf::Keyboard::Up, moveCameraUp);
	keyboard.bindKbd(sf::Keyboard::Down, moveCameraDown);
	keyboard.bindKbd(sf::Keyboard::Left, moveCameraLeft);
	keyboard.bindKbd(sf::Keyboard::Right, moveCameraRight);
	keyboard.bindKbd(sf::Keyboard::W, zoomIn);
	keyboard.bindKbd(sf::Keyboard::S, zoomOut);

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
		Render();
		window.display();
	}
	
	window.close();
	
	return 0;
}
