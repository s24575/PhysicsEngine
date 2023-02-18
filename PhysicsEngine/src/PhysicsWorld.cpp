#include "PhysicsWorld.h"

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
	for (Object* object : m_Objects)
	{
		object->Force = object->Mass * m_Gravity;

		object->Velocity += object->Force / object->Mass * dt;
		object->Position += object->Velocity * dt;

		object->Force = sf::Vector2f(0.0f, 0.0f);
	}
}