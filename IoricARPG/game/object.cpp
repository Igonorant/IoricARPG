#include "object.h"


void Object::Update(float dt)
{
	// Update general stuff of all objects
	pos += (vel * dt);
	animations[state].Update(dt);
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

void Object::AddAnimationFrame(Object::State animationState, unsigned int texID, float duration)
{
	animations[animationState].AddFrame(texID, duration);
}