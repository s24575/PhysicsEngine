#pragma once

#include "../CollisionPoints.h"
#include "Transform.h"
#include "Circle.h"
#include "Plane.h"

struct Collider
{
	virtual CollisionPoints TestCollision(const Transform* transform, const Collider* collider, const Transform* colliderTransform) const = 0;
	virtual CollisionPoints TestCollision(const Transform* transform, const Circle* circle, const Transform* circleTransform) const = 0;
	virtual CollisionPoints TestCollision(const Transform* transform, const Plane* plane, const Transform* planeTransform) const = 0;
};