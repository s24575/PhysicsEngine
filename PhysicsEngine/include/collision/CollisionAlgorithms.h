#pragma once

#include "Transform.h"
#include "colliders/Collider.h"
#include "colliders/CircleCollider.h"
#include "colliders/LineCollider.h"

namespace algo {
	CollisionPoints FindCircleCircleCollisionPoints(const CircleCollider* a, const Transform* at, const CircleCollider* b, const Transform* bt);
	CollisionPoints FindCircleLineCollisionPoints(const CircleCollider* a, const Transform* at, const LineCollider* b, const Transform* bt);
	CollisionPoints FindLineCircleCollisionPoints(const LineCollider* a, const Transform* at, const CircleCollider* b, const Transform* bt);
}