#pragma once

#include "collision/CollisionObject.h"

struct Rigidbody : public CollisionObject
{
	Rigidbody(glm::vec2 position, float mass)
		: m_Position(position),
		m_Mass(mass)
	{}

	glm::vec2 m_Position{ 0.0f, 0.0f };

	float m_Mass = 0.0f;
	glm::vec2 m_Velocity{ 0.0f, 0.0f };
	glm::vec2 m_Force{ 0.0f, 0.0f };

	glm::vec2 m_Gravity{ 0.0f, -9.81f };
	bool m_HasGravity = false;

	float m_StaticFriction = 0.0f;
	float m_DynamicFriction = 0.0f;
	float m_Restitution = 0.0f;
};