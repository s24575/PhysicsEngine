#pragma once

#include "Collider.h"

struct CircleCollider : public Collider
{
	virtual CollisionPoints TestCollision(const Transform* transform, const Collider* collider, const Transform* colliderTransform) const override;
	virtual CollisionPoints TestCollision(const Transform* transform, const Circle* circle, const Transform* circleTransform) const override;
	virtual CollisionPoints TestCollision(const Transform* transform, const Plane* plane, const Transform* planeTransform) const override;

	sf::Vector2f Center;
	float Radius;
};