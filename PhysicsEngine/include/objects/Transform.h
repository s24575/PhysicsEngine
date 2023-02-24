#pragma once

#include "glm/vec2.hpp"

struct Transform
{
	glm::vec2 m_Position{ 0.0f };
	glm::vec2 m_Scale{ 1.0f };
	float m_Rotation = 0.0f;
};