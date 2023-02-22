#pragma once

#include "objects/Object.h"

struct Collision
{
	Collision(Object* a, Object* b, CollisionPoints points)
		: ObjectA(a), ObjectB(b), Points(points)
	{}

	Object* ObjectA;
	Object* ObjectB;
	CollisionPoints Points;
};