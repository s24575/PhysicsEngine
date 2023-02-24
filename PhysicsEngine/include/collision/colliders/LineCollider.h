#pragma once

#include "Collider.h"

struct LineCollider : public Collider
{
	LineCollider(glm::vec2 origin, glm::vec2 direction, float distance);

	virtual CollisionPoints TestCollision(const Transform* transform, const Collider* collider, const Transform* colliderTransform) const override;
	virtual CollisionPoints TestCollision(const Transform* transform, const CircleCollider* circle, const Transform* circleTransform) const override;
	virtual CollisionPoints TestCollision(const Transform* transform, const LineCollider* line, const Transform* lineTransform) const override;

	glm::vec2 m_Origin;
	glm::vec2 m_Direction;
	float m_Distance;
};