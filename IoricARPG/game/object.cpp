#include "object.h"


void Object::Update(float dt)
{
	// Update general stuff of all objects
	lifeSpan -= dt;
	if (lifeSpan > 0.0f)
	{
		pos += (vel * dt);
		animations[state].Update(dt);
	}
	else
	{
		state = Object::State::MarkedForDeletion;
	}
}

unsigned int Object::GetCurrentTexID()
{
	if (animations.empty())
	{
		return texID;
	}
	else
	{
		return animations[state].GetFrame();
	}
}

float Object::GetScale()
{
	if (animations.empty())
	{
		return 0;
	}
	else
	{
		return animations[state].GetScale();
	}
}

void Object::AddAnimationFrame(Object::State animationState, unsigned int texID, float duration)
{
	animations[animationState].AddFrame(texID, duration);
}

void Object::AddAnimationFrame(Object::State animationState, unsigned int texID, float duration, float scale)
{
	animations[animationState].AddFrame(texID, duration,scale);
}