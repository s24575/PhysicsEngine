#include "collision/CollisionAlgorithms.h"

#include <cmath>

namespace algo {
	CollisionPoints FindCircleCircleCollisionPoints(const CircleCollider* a, const Transform* ta, const CircleCollider* b, const Transform* tb)
	{
		sf::Vector2f aPos = a->Center + ta->Position;
		sf::Vector2f bPos = b->Center + tb->Position;

		// Assume the scale is proportional and the radius is the same
		float aRadius = a->Radius * ta->Scale.x;
		float bRadius = b->Radius * tb->Scale.x;

		sf::Vector2f AtoB = b->Center - a->Center;
		sf::Vector2f BtoA = a->Center - b->Center;

		int distance = sqrt(AtoB.x * AtoB.x + AtoB.y + AtoB.y);

		if (distance <= a->Radius + b->Radius)
		{
			if (distance == 0) {
				// The circles are perfectly inside each other, offset one of them to the right
				aPos.x += aRadius;
				bPos.x += bRadius;
				return { aPos, bPos, sf::Vector2f{1.0f, 0.0f}, std::abs(aRadius - bRadius), true};
			}

			aPos += sf::Vector2f(AtoB.x * aRadius / distance, AtoB.y * aRadius / distance);
			bPos += sf::Vector2f(BtoA.x * bRadius / distance, BtoA.y * bRadius / distance);

			sf::Vector2f collisionAtoB = bPos - aPos;

			return { aPos, bPos, collisionAtoB, sqrt(collisionAtoB.x * collisionAtoB.x + collisionAtoB.y + collisionAtoB.y), true };
		}

		return {};
	}

	CollisionPoints FindCircleLineCollisionPoints(const CircleCollider* a, const Transform* ta, const LineCollider* b, const Transform* tb)
	{
		return {};
	}

	CollisionPoints FindLineCircleCollisionPoints(const LineCollider* a, const Transform* ta, const CircleCollider* b, const Transform* tb)
	{
		return {};
	}
}