#include "PhysicsWorld.h"

#include "collision/Collision.h"

#include <iostream>

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

void PhysicsWorld::Step(float dt)
{
	ResolveCollisions(dt);

	for (Object* object : m_Objects)
	{
		object->Force = object->Mass * m_Gravity;

		object->Velocity += object->Force / object->Mass * dt;
		object->Position += object->Velocity * dt;

		object->Force = sf::Vector2f(0.0f, 0.0f);
	}
}

void PhysicsWorld::ResolveCollisions(float dt)
{
	std::vector<Collision> collisions;
	for (Object* a : m_Objects)
	{
		for (Object* b : m_Objects)
		{
			// A and B exists, A and B are not the same
			if (a != b && a->m_Collider && b->m_Collider)
			{
				CollisionPoints points = a->m_Collider->TestCollision(a->m_Transform, b->m_Collider, b->m_Transform);

				if (points.hasCollision)
				{
					collisions.emplace_back(a, b, points);
				}
			}
		}
	}

	// Solve collisions
	for (const auto& collision : collisions)
	{
		std::cout << "Collision!\n";
	}
}