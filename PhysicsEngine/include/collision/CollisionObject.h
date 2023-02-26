#pragma once

#include "colliders/Collider.h"

struct CollisionObject
{
	Collider* m_Collider;
	Transform* m_Transform;
};