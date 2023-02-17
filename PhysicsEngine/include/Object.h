#pragma once

#include "SFML/Graphics.hpp"

struct Object : public sf::Drawable, public sf::Transformable
{
	Object()
	{
		Id = uniqueId;
		uniqueId++;
	}

	static uint32_t uniqueId;

	uint32_t Id;
	sf::Vector2f Position;
	sf::Vector2f Velocity;
	sf::Vector2f Force;
	float Mass;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {}
};