#include "collision/colliders/LineCollider.h"

#include "collision/CollisionAlgorithms.h"

LineCollider::LineCollider(sf::Vector2f origin, sf::Vector2f direction, float distance)
	: Origin(origin), Direction(direction), Distance(distance) {}

CollisionPoints LineCollider::TestCollision(const Transform* transform, const Collider* collider, const Transform* colliderTransform) const
{
	return collider->TestCollision(colliderTransform, this, transform);
}

CollisionPoints LineCollider::TestCollision(const Transform* transform, const CircleCollider* circle, const Transform* circleTransform) const
{
	return algo::FindLineCircleCollisionPoints(this, transform, circle, circleTransform);
}

CollisionPoints LineCollider::TestCollision(const Transform* transform, const LineCollider* line, const Transform* lineTransform) const
{
	return {};
}