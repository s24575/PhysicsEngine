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

		glm::vec2 AtoB = b->m_Center - a->m_Center;
		glm::vec2 BtoA = -AtoB;

		float distanceSquared = glm::dot(AtoB, AtoB);
		float radiusSumSquared = (a->m_Radius + b->m_Radius) * (a->m_Radius + b->m_Radius);

		// avoid using sqrt: distance <= aRadius + bRadius
		if (distanceSquared < radiusSumSquared)
		{
			if (distanceSquared == 0.0f) {
				// The circles are perfectly inside each other, offset one of them to the top
				aPos.y += aRadius;
				bPos.y += bRadius;
				return { aPos, bPos, glm::vec2(0.0f, 1.0f), std::max(aRadius, bRadius), true};
			}

			float distance = std::sqrt(distanceSquared);

			aPos += aRadius / distance * AtoB;
			bPos += bRadius / distance * BtoA;

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

		glm::vec2 vctr = aCenter - onPlane;
		float distance = std::abs(glm::dot(normal, vctr));

		if (distance > aRadius)
		{
			return {};
		}

		glm::vec2 aPos = aCenter - normal * aRadius;
		glm::vec2 bPos = aCenter - normal * distance;

		return CollisionPoints(aPos, bPos, normal, distance, true);
	}

	CollisionPoints FindLineCircleCollisionPoints(const LineCollider* a, const Transform* ta, const CircleCollider* b, const Transform* tb)
	{
		return FindCircleLineCollisionPoints(b, tb, a, ta);
	}
}