#pragma once

#include "SFML/Graphics.hpp"

#include "collision/colliders/Collider.h"

struct Object : public sf::Drawable//, public sf::Transformable
{
	Object(glm::vec2 position, float mass)
		: m_Position(position),
		m_Mass(mass) {}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {}
	virtual void update() {}

	virtual Collider* GetCollider() { return nullptr; }

	glm::vec2 m_Position{ 0.0f, 0.0f };

	float m_Mass = 0.0f;
	glm::vec2 m_Velocity{ 0.0f, 0.0f };
	glm::vec2 m_Force{ 0.0f, 0.0f };

	bool m_HasGravity = false;

	Transform* m_Transform = nullptr;
};