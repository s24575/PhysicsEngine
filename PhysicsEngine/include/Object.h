#pragma once

#include "SFML/Graphics.hpp"

struct Object : public sf::Drawable, public sf::Transformable
{
	Object(sf::Vector2f pos, float mass)
		: Mass(mass),
		  Position(pos)
	{}

	sf::Vector2f Position{ 0.0f, 0.0f };
	sf::Vector2f Velocity{ 0.0f, 0.0f };
	sf::Vector2f Force{ 0.0f, 0.0f };
	float Mass = 0.0f;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {}
	virtual void update() {}
};