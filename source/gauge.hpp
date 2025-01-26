/*
 * gauge.hpp
 *
 * Rotating gauge class for visualizing speed.
 *
 * 26-01-2025 by madpl
 */
#pragma once

#include <SFML/Graphics.hpp>
#include "defines.hpp"


class CRotatingGauge
{
public:
	CRotatingGauge(float x, float y, float radius):
		m_position(x, y),
		m_radius(radius)
	{
		// initialize circle of gauge
		m_circle.setRadius(m_radius);
		m_circle.setOutlineColor(sf::Color::White);
		m_circle.setOutlineThickness(3.0f);
		m_circle.setFillColor(sf::Color::Transparent);
		m_circle.setPosition(m_position.x - m_radius, m_position.y - m_radius);
		
		// clue length and thickness of gauge
		m_clue.setSize(sf::Vector2f(m_radius, 2.0f));
		m_clue.setOrigin(m_radius * 0.1, 1.0f); // rotate from one end
		m_clue.setFillColor(sf::Color::Red);
		m_clue.setPosition(m_position);
	}
	
	void draw(sf::RenderWindow& window, float value, float maxValue)
	{
		// Clamp value to the range [0, maxValue]
		if(value < 0.0f)
			value = 0.0f;
		
		if(value > maxValue)
			value = maxValue;
		
		// calculate clue's angle
		// 180 degrees max rotation
		float angle = (value / maxValue) * 180.0f;
		m_clue.setRotation(angle);
		
		// Draw the gauge
		window.draw(m_circle);
		window.draw(m_clue);
	}
	
private:
	sf::Vector2f m_position;		// position of gauge
	float m_radius;					// radius of gauge
	sf::CircleShape m_circle;		// Circle representing the gauge
	sf::RectangleShape m_clue;		// clue representing the current value
};
