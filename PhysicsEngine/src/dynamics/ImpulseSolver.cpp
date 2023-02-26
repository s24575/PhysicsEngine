#include "dynamics/ImpulseSolver.h"

#include "glm/glm.hpp"

void ImpulseSolver::Solve(std::vector<Collision>& collisions, float dt)
{
	for (Collision& collision : collisions)
	{
		CollisionPoints& points = collision.Points;

		Object* objectA = nullptr;
		float aInvertedMass = 1.0f;
		glm::vec2 aVelocity(0.0f);

		Object* objectB = nullptr;
		float bInvertedMass = 1.0f;
		glm::vec2 bVelocity(0.0f);

		if (collision.ObjectA->m_HasGravity)
		{
			objectA = collision.ObjectA;
			aInvertedMass = 1.0f / objectA->m_Mass;
			aVelocity = objectA->m_Velocity;
		}

		if (collision.ObjectB->m_HasGravity)
		{
			objectB = collision.ObjectB;
			bInvertedMass = 1.0f / objectB->m_Mass;
			bVelocity = objectB->m_Velocity;
		}

		glm::vec2 relativeVelocity = bVelocity - aVelocity;
		float speedAlongNormal = glm::dot(relativeVelocity, points.Normal);

		//if (speed >= 0)
		//	continue;

		float e = 1.0f;
		float j = -(1.0f + e) * speedAlongNormal / (aInvertedMass + bInvertedMass);

		glm::vec2 impulse = j * points.Normal;

		if (objectA)
		{
			aVelocity -= impulse * aInvertedMass;
			objectA->m_Velocity = aVelocity;
		}

		if (objectB)
		{
			bVelocity += impulse * bInvertedMass;
			objectB->m_Velocity = bVelocity;
		}
	}
}