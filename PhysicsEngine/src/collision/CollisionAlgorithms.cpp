#include "collision/CollisionAlgorithms.h"

#include <cmath>
#include <algorithm>

namespace algo {
	CollisionPoints FindCircleCircleCollisionPoints(const CircleCollider* a, const Transform* ta, const CircleCollider* b, const Transform* tb)
	{
		sf::Vector2f aPos = a->Center + ta->Position;
		sf::Vector2f bPos = b->Center + tb->Position;

		// Assume the scale is proportional and the radius is the same
		float aRadius = a->Radius * ta->Scale.x;
		float bRadius = b->Radius * tb->Scale.x;

		sf::Vector2f AtoB = b->Center - a->Center;
		sf::Vector2f BtoA = -AtoB;

		float distanceSquared = AtoB.x * AtoB.x + AtoB.y * AtoB.y;
		float radiusSumSquared = (a->Radius + b->Radius) * (a->Radius + b->Radius);

		// avoid using sqrt: distance <= aRadius + bRadius
		if (distanceSquared < radiusSumSquared)
		{
			if (distanceSquared == 0.0f) {
				// The circles are perfectly inside each other, offset one of them to the top
				aPos.y += aRadius;
				bPos.y += bRadius;
				return { aPos, bPos, sf::Vector2f{0.0f, 1.0f}, std::max(aRadius, bRadius), true};
			}

			float distance = std::sqrt(distanceSquared);

			aPos += aRadius / distance * AtoB;
			bPos += bRadius / distance * BtoA;

			sf::Vector2f collisionAtoB = bPos - aPos;
			float depth = aRadius + bRadius - distance;

			return { aPos, bPos, collisionAtoB, depth, true };
		}

		return {};
	}

	CollisionPoints FindCircleLineCollisionPoints(const CircleCollider* a, const Transform* ta, const LineCollider* b, const Transform* tb)
	{
		sf::Vector2f aCenter = a->Center + ta->Position;
		float aRadius = a->Radius * ta->Scale.x;

		sf::Vector2f normal = sf::Vector2f(b->Direction.y, -b->Direction.x);
		sf::Vector2f onPlane = b->Origin + tb->Position;

		sf::Vector2f vctr = aCenter - onPlane;
		float distance = std::abs(normal.x * vctr.x + normal.y * vctr.y);

		if (distance > aRadius)
		{
			return {};
		}

		sf::Vector2f aPos = aCenter - normal * aRadius;
		sf::Vector2f bPos = aCenter - normal * distance;

		return CollisionPoints(aPos, bPos, normal, distance, true);
	}

	CollisionPoints FindLineCircleCollisionPoints(const LineCollider* a, const Transform* ta, const CircleCollider* b, const Transform* tb)
	{
		return FindCircleLineCollisionPoints(b, tb, a, ta);
	}
}