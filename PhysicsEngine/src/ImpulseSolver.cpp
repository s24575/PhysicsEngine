#include "ImpulseSolver.h"

void ImpulseSolver::Solve(std::vector<Collision>& collisions, float dt)
{
	for (Collision& collision : collisions)
	{
		Object* objectA = collision.ObjectA;
		Object* objectB = collision.ObjectB;

		CollisionPoints& points = collision.Points;

		if (!objectA->m_HasGravity)
		{
			objectB->m_Velocity = glm::vec2(0.0f);
		}
		else if (!objectB->m_HasGravity)
		{
			objectA->m_Velocity = glm::vec2(0.0f);
		}
		else
		{
			objectA->m_Position -= points.Normal * points.Depth / 2.0f * dt;
			objectB->m_Position += points.Normal * points.Depth / 2.0f * dt;
		}

		//CollisionPoints& points = collision.Points;

		//Object* objectA = nullptr;
		//float aInvertedMass = 1.0f;
		//sf::Vector2f aVelocity(0.0f, 0.0f);

		//Object* objectB = nullptr;
		//float bInvertedMass = 1.0f;
		//sf::Vector2f bVelocity(0.0f, 0.0f);

		//if (collision.ObjectA->hasGravity)
		//{
		//	objectA = collision.ObjectA;
		//	aInvertedMass = 1.0f / objectA->Mass;
		//	aVelocity = objectA->Velocity;
		//}

		//if (collision.ObjectB->hasGravity)
		//{
		//	objectB = collision.ObjectB;
		//	bInvertedMass = 1.0f / objectB->Mass;
		//	bVelocity = objectB->Velocity;
		//}

		//sf::Vector2f diffVelocity = bVelocity - aVelocity;
		//float speed = diffVelocity.x * points.Normal.x + diffVelocity.y * points.Normal.y;

		//if (speed >= 0)
		//	continue;

		//float e = 1.0f;
		//float j = -(1.0f - e) * speed / (aInvertedMass + bInvertedMass);

		//sf::Vector2f impulse = j * points.Normal;

		//if (objectA)
		//{
		//	aVelocity -= impulse * aInvertedMass;
		//	objectA->Velocity = aVelocity;
		//}

		//if (objectB)
		//{
		//	bVelocity += impulse * bInvertedMass;
		//	objectB->Velocity = bVelocity;
		//}
	}
}