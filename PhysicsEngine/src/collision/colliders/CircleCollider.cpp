#include "collision/colliders/CircleCollider.h"

#include "collision/CollisionAlgorithms.h"

CircleCollider::CircleCollider(glm::vec2 center, float radius)
	: m_Center(center), m_Radius(radius) {}

CollisionPoints CircleCollider::TestCollision(const Transform* transform, const Collider* collider, const Transform* colliderTransform) const
{
	return collider->TestCollision(colliderTransform, this, transform);
}

CollisionPoints CircleCollider::TestCollision(const Transform* transform, const CircleCollider* circle, const Transform* circleTransform) const
{
	return algo::FindCircleCircleCollisionPoints(this, transform, circle, circleTransform);
}

CollisionPoints CircleCollider::TestCollision(const Transform* transform, const LineCollider* line, const Transform* lineTransform) const
{
	return algo::FindCircleLineCollisionPoints(this, transform, line, lineTransform);
}