#include "PhysicsWorld.h"

void PhysicsWorld::AddObject(Object* object)
{
	if (object)
	{
		m_Objects[object->Id] = object;
	}
}

void PhysicsWorld::RemoveObject(Object* object)
{
	if (object)
	{
		m_Objects[object->Id] = nullptr;
	}
}

void PhysicsWorld::Step(float dt)
{
	for (const auto& entry : m_Objects)
	{
		Object* object = entry.second;

		if (!object)
			continue;

		object->Force += object->Mass * m_Gravity;
		object->Velocity += object->Force / object->Mass * dt;
		object->Position += object->Velocity * dt;

		object->Force = sf::Vector2f(0.0f, 0.0f);
	}
}