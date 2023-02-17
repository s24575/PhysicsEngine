#pragma once

#include "Object.h"

struct Circle : public Object
{
	Circle(float radius)
		: Object(),
		Radius(radius)
	{

	}

	sf::CircleShape CircleShape;
	float Radius;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(CircleShape, states);
	}
};