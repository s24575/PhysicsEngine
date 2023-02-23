#include "ImpulseSolver.h"

void ImpulseSolver::Solve(std::vector<Collision>& collisions, float dt)
{
	for (Collision& collision : collisions)
	{
		Object* objectA = collision.ObjectA;
		Object* objectB = collision.ObjectB;

		CollisionPoints& points = collision.Points;

		if (!objectA->hasGravity)
		{
			objectB->Velocity = sf::Vector2f(0.0f, 0.0f);
			objectB->Position += points.Normal * points.Depth * dt;
		}
		else if (!objectB->hasGravity)
		{
			objectA->Velocity = sf::Vector2f(0.0f, 0.0f);
			objectA->Position += -points.Normal * points.Depth * dt;
		}
		else
		{
			objectA->Position += -points.Normal * points.Depth / 2.0f * dt;
			objectB->Position += points.Normal * points.Depth / 2.0f * dt;
		}
	}
}