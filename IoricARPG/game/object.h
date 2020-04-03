#pragma once

#include "../math/vec2.h"

class Object
{
public:
	virtual void Update(float dt) {};
public:
	unsigned int texID;
	Vec2 pos;
	Vec2 vel;
	float scale;
};