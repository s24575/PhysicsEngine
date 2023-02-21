#include "collision/CollisionPoints.h"

CollisionPoints::CollisionPoints() {}

CollisionPoints::CollisionPoints(sf::Vector2f a, sf::Vector2f b, sf::Vector2f normal, float depth, bool hasCollision = true)
	: A(a), B(b), Normal(normal), Depth(depth), hasCollision(hasCollision) {}