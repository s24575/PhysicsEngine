#pragma once

#include "SFML/System/Vector2.hpp"

struct Transform
{
	sf::Vector2f Position{ 0.0f, 0.0f };
	sf::Vector2f Scale{ 1.0f, 1.0f };
	float Rotation = 0.0f;
};