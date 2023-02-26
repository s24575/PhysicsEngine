#pragma once

#include "collision/Collision.h"

#include <vector>

class Solver
{
public:
	virtual void Solve(std::vector<Collision>& collisions, float dt) = 0;
};