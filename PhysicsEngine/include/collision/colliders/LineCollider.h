#pragma once

#include "Collider.h"

struct LineCollider : public Collider
{
	virtual CollisionPoints TestCollision(const Transform* transform, const Collider* collider, const Transform* colliderTransform) const override;
	virtual CollisionPoints TestCollision(const Transform* transform, const CircleCollider* circle, const Transform* circleTransform) const override;
	virtual CollisionPoints TestCollision(const Transform* transform, const LineCollider* line, const Transform* lineTransform) const override;

	sf::Vector2f Line;
	float Distance;
};