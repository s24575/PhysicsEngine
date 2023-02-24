#pragma once

#include "Object.h"

#include "collision/colliders/CircleCollider.h"

struct Circle : public Object
{
	Circle(glm::vec2 pos, float radius, float mass)
		: Object(pos, mass),
		m_Radius(radius),
		m_CircleShape(radius) {}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(m_CircleShape, states);
	}

	virtual void update() override
	{
		m_CircleShape.setPosition(sf::Vector2f(m_Position.x, m_Position.y) - sf::Vector2f(m_Radius, m_Radius));

		m_CircleCollider->m_Center = m_Position;
		m_CircleCollider->m_Radius = m_Radius;
	}

	virtual Collider* GetCollider() override
	{
		return (Collider*)m_CircleCollider;
	}

	float m_Radius;

	sf::CircleShape m_CircleShape;
	CircleCollider* m_CircleCollider = nullptr;
};