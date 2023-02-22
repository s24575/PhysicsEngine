#include "ImpulseSolver.h"

void ImpulseSolver::Solve(std::vector<Collision>& collisions, float dt)
{
	for (Collision& collision : collisions)
	{
		Object* objectA = collision.ObjectA;
		Object* objectB = collision.ObjectB;

		CollisionPoints& points = collision.Points;

		objectA->Position += -points.Normal * points.Depth / 2.0f * dt;
		objectB->Position += points.Normal * points.Depth / 2.0f * dt;
	}
}