#include "collision/CollisionAlgorithms.h"

namespace algo {
	CollisionPoints FindCircleCircleCollisionPoints(const CircleCollider* a, const Transform* at, const CircleCollider* b, const Transform* bt)
	{
		return {};
	}

	CollisionPoints FindCircleLineCollisionPoints(const CircleCollider* a, const Transform* at, const LineCollider* b, const Transform* bt)
	{
		return {};
	}

	CollisionPoints FindLineCircleCollisionPoints(const LineCollider* a, const Transform* at, const CircleCollider* b, const Transform* bt)
	{
		return {};
	}
}