#pragma once

#include "Transform.h"
#include "colliders/Collider.h"
#include "colliders/CircleCollider.h"
#include "colliders/LineCollider.h"

namespace algo {
	CollisionPoints FindCircleCircleCollisionPoints(const CircleCollider* a, const Transform* ta, const CircleCollider* b, const Transform* tb);
	CollisionPoints FindCircleLineCollisionPoints(const CircleCollider* a, const Transform* ta, const LineCollider* b, const Transform* tb);
	CollisionPoints FindLineCircleCollisionPoints(const LineCollider* a, const Transform* ta, const CircleCollider* b, const Transform* tb);
}