#pragma once

#include "collision/CollisionPoints.h"
#include "Transform.h"

struct CircleCollider;
struct LineCollider;

struct Collider
{
	virtual CollisionPoints TestCollision(const Transform* transform, const Collider* collider, const Transform* colliderTransform) const = 0;
	virtual CollisionPoints TestCollision(const Transform* transform, const CircleCollider* circle, const Transform* circleTransform) const = 0;
	virtual CollisionPoints TestCollision(const Transform* transform, const LineCollider* line, const Transform* lineTransform) const = 0;
};