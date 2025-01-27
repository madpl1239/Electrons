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
	CRotatingGauge(float x, float y, float radius, sf::Font& font):
		m_position(x, y),
		m_radius(radius),
		m_font(font)
	{
		// initialize circle of gauge
		m_circle.setRadius(m_radius);
		m_circle.setOutlineColor(GAUGECIRCLE);
		m_circle.setOutlineThickness(3.0f);
		m_circle.setFillColor(sf::Color::Transparent);
		m_circle.setPosition(m_position.x - m_radius, m_position.y - m_radius);
		
		// clue length and thickness of gauge
		m_clue.setSize(sf::Vector2f(m_radius, 2.0f));
		m_clue.setOrigin(m_radius * 0.2, 1.0f); // rotate from one end
		m_clue.setFillColor(GAUGECLUE);
		m_clue.setPosition(m_position);
	}
	
	void draw(sf::RenderWindow& window, float value, float maxValue)
	{
		// Clamp value to the range [0, maxValue]
		if(value < 0.0f)
			value = 0.0f;
		
		if(value > maxValue)
			value = maxValue;
		
		float minAngle = 150.0f;
		float maxAngle = -60.0f;
		
		// calculate clue's angle
		// 180 degrees max rotation
		float angle = minAngle + ((value / maxValue) * (minAngle - maxAngle));
		m_clue.setRotation(angle);
		
		// Draw the gauge
		window.draw(m_circle);
		window.draw(m_clue);
		
		sf::Text speedText;
		speedText.setFont(m_font);
		speedText.setString("speed: " + std::to_string(value).substr(0, 4));
		speedText.setCharacterSize(12);
		speedText.setFillColor(GAUGECIRCLE);
		
		// position of text
		sf::FloatRect textBounds = speedText.getLocalBounds();
		speedText.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
		speedText.setPosition(m_position.x, m_position.y + m_radius + 20.0f);
		
		window.draw(speedText);
	}
	
private:
	sf::Font m_font;
	
	sf::CircleShape m_circle;		// Circle representing the gauge
	sf::RectangleShape m_clue;		// clue representing the current value
	
	sf::Vector2f m_position;		// position of gauge
	float m_radius;					// radius of gauge
};
