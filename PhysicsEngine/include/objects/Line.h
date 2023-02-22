#pragma once

#include "Object.h"

#include "collision/colliders/LineCollider.h"

struct Line : public Object
{
	Line(sf::Vector2f origin, sf::Vector2f direction, float distance, float mass)
		: Object(origin, mass),
		m_Origin(origin),
		m_Direction(direction),
		m_Distance(distance)
	{
		m_Line[0] = sf::Vertex(origin);
		sf::Vector2f end = origin + direction * distance;
		m_Line[1] = sf::Vertex(end);
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(m_Line, 2, sf::Lines);
	}

	virtual void update() override
	{
		UpdateVertices();
		m_LineCollider->Origin = m_Origin;
	}

	virtual Collider* GetCollider() override
	{
		return (Collider*)m_LineCollider;
	}

	void UpdateVertices()
	{
		m_Line[0].position = m_Origin;
		sf::Vector2f end = m_Origin + m_Direction * m_Distance;
		m_Line[1].position = end;
	}

	sf::Vector2f m_Origin;
	sf::Vector2f m_Direction;
	float m_Distance;

	sf::Vertex m_Line[2];
	LineCollider* m_LineCollider = nullptr;
};