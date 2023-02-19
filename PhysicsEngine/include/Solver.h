#pragma once

#include "Object.h"

#include <vector>

class Solver
{
public:
	void checkCollisions(std::vector<Object*> objects);
};