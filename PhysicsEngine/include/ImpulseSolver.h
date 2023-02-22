#pragma once

#include "Solver.h"

class ImpulseSolver : public Solver
{
	virtual void Solve(std::vector<Collision>& collisions, float dt) override;
};