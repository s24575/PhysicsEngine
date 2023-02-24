#pragma once

#include "glm/vec2.hpp"

struct CollisionPoints
{
	glm::vec2 A{ 0.0f, 0.0f };
	glm::vec2 B{ 0.0f, 0.0f };
	glm::vec2 Normal{ 0.0f, 0.0f };
	float Depth = 0.0f;
	bool hasCollision = false;

	CollisionPoints();
	CollisionPoints(glm::vec2 a, glm::vec2 b, glm::vec2 normal, float depth, bool hasCollision = true);
};