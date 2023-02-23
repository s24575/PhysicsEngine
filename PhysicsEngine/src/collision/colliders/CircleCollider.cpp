#include "collision/colliders/CircleCollider.h"

#include "collision/CollisionAlgorithms.h"

CircleCollider::CircleCollider(sf::Vector2f center, float radius)
	: Center(center), Radius(radius) {}

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