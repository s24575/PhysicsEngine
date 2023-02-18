#pragma once

#include "PhysicsWorld.h"

#include <SFML/Graphics.hpp>

#include <cstdint>

class Renderer
{
public:
	Renderer();

	void OnResize(uint32_t width, uint32_t height);
	void Render(sf::RenderWindow& window, const PhysicsWorld& physicsWorld);
};