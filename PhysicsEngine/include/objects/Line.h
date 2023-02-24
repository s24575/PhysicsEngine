#pragma once

#include "Object.h"

#include "collision/colliders/LineCollider.h"

struct Line : public Object
{
	Line(glm::vec2 origin, glm::vec2 direction, float distance, float mass)
		: Object(origin, mass),
		m_Origin(origin),
		m_Direction(direction),
		m_Distance(distance)
	{
		m_Line[0] = sf::Vertex(sf::Vector2f(origin.x, origin.y), sf::Color::Red);
		m_Line[1] = sf::Vertex(sf::Vector2f(origin.x, origin.y) + sf::Vector2f(direction.x, direction.y) * distance, sf::Color::Red);
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(m_Line, 2, sf::Lines);
	}

	virtual void update() override
	{
		UpdateVertices();
		if (m_LineCollider)
		{
			m_LineCollider->m_Origin = m_Position;
			m_LineCollider->m_Direction = m_Direction;
			m_LineCollider->m_Distance = m_Distance;
		}
	}

	virtual Collider* GetCollider() override
	{
		return (Collider*)m_LineCollider;
	}

	void UpdateVertices()
	{
		m_Line[0].position = sf::Vector2f(m_Position.x, m_Position.y);
		m_Line[1].position = sf::Vector2f(m_Position.x, m_Position.y) + sf::Vector2f(m_Direction.x, m_Direction.y) * m_Distance;
	}

	glm::vec2 m_Origin;
	glm::vec2 m_Direction;
	float m_Distance;

	sf::Vertex m_Line[2];
	LineCollider* m_LineCollider = nullptr;
};