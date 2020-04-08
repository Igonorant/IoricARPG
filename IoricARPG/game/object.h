#pragma once

#include "../math/vec2.h"
#include <map>
#include <string>
#include "../engine/animation.h"

class Object
{
public:
	enum State
	{
		NotInitialized = 0,
		Idle,
		MovingLeft,
		MovingRight,
		MovingDown,
		MovingUp
	};

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

	// virtual methods
	virtual void Update(float dt);

	// non-virtual methods
	unsigned int GetCurrentTexID();
	inline void SetState(Object::State newState)
	{
		state = newState;
	}
	void AddAnimationFrame(Object::State animationState, unsigned int texID, float duration);


public:
	Vec2 pos;
	Vec2 vel;
	float scale;

protected:
	std::map<Object::State, Animation> animations;
	Object::State state;
	unsigned int texID;
};