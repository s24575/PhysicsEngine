#pragma once

#include "Object.h"

struct Circle : public Object
{
	Circle(sf::Vector2f pos, float mass, float radius)
		: Object(pos, mass),
		m_CircleShape(radius),
		m_Radius(radius)
	{

	}

	sf::CircleShape m_CircleShape;
	float m_Radius;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(m_CircleShape, states);
	}

	virtual void update() override
	{
		m_CircleShape.setPosition(Position);
	}
};