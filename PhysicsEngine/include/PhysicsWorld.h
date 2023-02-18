#pragma once

#include "Object.h"

#include <vector>

class PhysicsWorld
{
public:

	void AddObject(Object* object);
	void RemoveObject(Object* object);
	void Step(float dt);

	std::vector<Object*> GetObjects() const { return m_Objects; }
private:
	std::vector<Object*> m_Objects;
	const sf::Vector2f m_Gravity{ 0.0f, 9.81f };
};