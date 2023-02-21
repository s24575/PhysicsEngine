#pragma once

#include "SFML/System/Vector2.hpp"

struct CollisionPoints
{
	sf::Vector2f A{ 0.0f, 0.0f };
	sf::Vector2f B{ 0.0f, 0.0f };
	sf::Vector2f Normal{ 0.0f, 0.0f };
	float Depth = 0.0f;
	bool hasCollision = false;

	CollisionPoints();
	CollisionPoints(sf::Vector2f a, sf::Vector2f b, sf::Vector2f normal, float depth, bool hasCollision = true);
};