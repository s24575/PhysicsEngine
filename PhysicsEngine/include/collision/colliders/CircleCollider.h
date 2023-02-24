#pragma once

#include "Collider.h"

struct CircleCollider : public Collider
{
	CircleCollider(glm::vec2 center, float radius);

	virtual CollisionPoints TestCollision(const Transform* transform, const Collider* collider, const Transform* colliderTransform) const override;
	virtual CollisionPoints TestCollision(const Transform* transform, const CircleCollider* circle, const Transform* circleTransform) const override;
	virtual CollisionPoints TestCollision(const Transform* transform, const LineCollider* line, const Transform* lineTransform) const override;

	glm::vec2 m_Center;
	float m_Radius;
};