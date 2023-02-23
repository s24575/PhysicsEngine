#pragma once

#include "Object.h"

#include "collision/colliders/CircleCollider.h"

struct Circle : public Object
{
	Circle(sf::Vector2f pos, float mass, float radius)
		: Object(pos, mass),
		m_CircleShape(radius) {}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(m_CircleShape, states);
	}

	virtual void update() override
	{
		m_CircleShape.setPosition(Position - sf::Vector2f(m_CircleShape.getRadius(), m_CircleShape.getRadius()));
		m_CircleCollider->Center = Position;
		m_CircleCollider->Radius = m_CircleShape.getRadius();
	}

	virtual Collider* GetCollider() override
	{
		return (Collider*)m_CircleCollider;
	}

	sf::CircleShape m_CircleShape;
	CircleCollider* m_CircleCollider = nullptr;
};