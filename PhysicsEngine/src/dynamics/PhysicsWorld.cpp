#include "dynamics/PhysicsWorld.h"

#include "collision/Collision.h"

void PhysicsWorld::AddObject(Object* object)
{
	m_Objects.push_back(object);
}

void PhysicsWorld::RemoveObject(Object* object)
{
	if (!object)
		return;

	auto itr = std::find(m_Objects.begin(), m_Objects.end(), object);
	if (itr != m_Objects.end())
		m_Objects.erase(itr);
}

void PhysicsWorld::AddSolver(Solver* solver)
{
	m_Solvers.push_back(solver);
}

void PhysicsWorld::RemoveSolver(Solver* solver)
{
	if (!solver)
		return;

	auto itr = std::find(m_Solvers.begin(), m_Solvers.end(), solver);
	if (itr != m_Solvers.end())
		m_Solvers.erase(itr);
}

void PhysicsWorld::Step(float dt)
{
	ResolveCollisions(dt);

	for (Object* object : m_Objects)
	{
		if (object->m_HasGravity)
		{
			object->m_Force = object->m_Mass * m_Gravity;
			object->m_Velocity += object->m_Force / object->m_Mass * dt;
			object->m_Position += object->m_Velocity * dt;

			object->m_Force = glm::vec2(0.0f);
		}
	}
}

void PhysicsWorld::ResolveCollisions(float dt)
{
	std::vector<Collision> collisions;

	for (size_t i = 0; i < m_Objects.size(); i++)
	{
		for (size_t j = i + 1; j < m_Objects.size(); j++)
		{
			Object* a = m_Objects[i];
			Object* b = m_Objects[j];

			if (a->GetCollider() && b->GetCollider())
			{
				CollisionPoints points = a->GetCollider()->TestCollision(a->m_Transform, b->GetCollider(), b->m_Transform);

				if (points.hasCollision)
				{
					collisions.emplace_back(a, b, points);
				}
			}
		}
	}

	for (Solver* solver : m_Solvers)
	{
		solver->Solve(collisions, dt);
	}
}