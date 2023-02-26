#include "collision/CollisionAlgorithms.h"

#include <cmath>
#include <algorithm>

#include "glm/glm.hpp"

namespace algo {
	CollisionPoints FindCircleCircleCollisionPoints(const CircleCollider* a, const Transform* ta, const CircleCollider* b, const Transform* tb)
	{
		glm::vec2 aPos = a->m_Center + ta->m_Position;
		glm::vec2 bPos = b->m_Center + tb->m_Position;

		// Assume the scale is proportional and the radius is the same
		float aRadius = a->m_Radius * ta->m_Scale.x;
		float bRadius = b->m_Radius * tb->m_Scale.x;

		glm::vec2 AtoB = bPos - aPos;

		float distanceSquared = glm::dot(AtoB, AtoB);
		float radiusSumSquared = (aRadius + bRadius) * (aRadius + bRadius);

		// avoid using sqrt: distance <= aRadius + bRadius
		if (distanceSquared <= radiusSumSquared)
		{
			if (distanceSquared == 0.0f) {
				// The circles are perfectly inside each other, offset one of them to the top
				aPos.y += aRadius;
				bPos.y += bRadius;
				return { aPos, bPos, glm::vec2(0.0f, 1.0f), std::max(aRadius, bRadius), true};
			}

			float distance = std::sqrt(distanceSquared);

			aPos += aRadius / distance * AtoB;
			bPos -= bRadius / distance * AtoB;

			glm::vec2 collisionAtoB = bPos - aPos;
			float depth = aRadius + bRadius - distance;

			return { aPos, bPos, collisionAtoB, depth, true };
		}

		return {};
	}

	CollisionPoints FindCircleLineCollisionPoints(const CircleCollider* a, const Transform* ta, const LineCollider* b, const Transform* tb)
	{
		glm::vec2 aCenter = a->m_Center + ta->m_Position;
		float aRadius = a->m_Radius * ta->m_Scale.x;

		glm::vec2 normal = glm::vec2(-b->m_Direction.y, b->m_Direction.x);
		glm::vec2 onPlane = b->m_Origin + tb->m_Position;

		float distance = glm::dot(normal, aCenter - onPlane);
		float absDistance = std::abs(distance);

		if (absDistance <= aRadius)
		{
			float offset = aRadius - absDistance;

			if (distance < 0.0f)
			{
				normal = -normal;
			}

			glm::vec2 aPos = aCenter - normal * aRadius;
			glm::vec2 bPos = aCenter - normal * absDistance;

			return CollisionPoints(aPos, bPos, normal, offset, true);
		}

		return {};
	}

	CollisionPoints FindLineCircleCollisionPoints(const LineCollider* a, const Transform* ta, const CircleCollider* b, const Transform* tb)
	{
		return FindCircleLineCollisionPoints(b, tb, a, ta);
	}
}