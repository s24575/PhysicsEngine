#pragma once

#include "Object.h"

//#include <vector>
#include <unordered_map>

class PhysicsWorld
{
public:

	void AddObject(Object* object);
	void RemoveObject(Object* object);
	void Step(float dt);

	std::unordered_map<uint64_t, Object*> GetObjects() const { return m_Objects; }
private:
	std::unordered_map<uint64_t, Object*> m_Objects;
	const sf::Vector2f m_Gravity{ 0.0f, 9.81f };
};