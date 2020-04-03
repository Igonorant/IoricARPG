#pragma once

#include "../math/vec2.h"

class Object
{
public:
	Object()
		:texID(0), scale(0)
	{}
	Object(unsigned int texID, float x, float y, float scale)
		:texID(texID), scale(scale)
	{
		pos.x = x;
		pos.y = y;
	}

	virtual void Update(float dt) {};
public:
	unsigned int texID;
	Vec2 pos;
	Vec2 vel;
	float scale;
};