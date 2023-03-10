#pragma once

#include "objects/Object.h"
#include "Solver.h"

#include <vector>

class PhysicsWorld
{
public:

	void AddObject(Object* object);
	void RemoveObject(Object* object);

	void AddSolver(Solver* solver);
	void RemoveSolver(Solver* solver);

	void Step(float dt);

	void ResolveCollisions(float dt);

	std::vector<Object*> GetObjects() const { return m_Objects; }
private:
	std::vector<Object*> m_Objects;
	std::vector<Solver*> m_Solvers;
	glm::vec2 m_Gravity{ 0.0f, 9.81f };
};