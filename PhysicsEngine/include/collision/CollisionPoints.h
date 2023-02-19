#pragma once

#include "SFML/System/Vector2.hpp"

struct CollisionPoints
{
	sf::Vector2f A;
	sf::Vector2f B;
	sf::Vector2f Normal;
	float Depth;
	bool hasCollision;
};