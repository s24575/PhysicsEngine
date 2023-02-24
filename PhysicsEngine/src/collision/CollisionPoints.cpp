#include "collision/CollisionPoints.h"

CollisionPoints::CollisionPoints() {}

CollisionPoints::CollisionPoints(glm::vec2 a, glm::vec2 b, glm::vec2 normal, float depth, bool hasCollision)
	: A(a), B(b), Normal(normal), Depth(depth), hasCollision(hasCollision) {}