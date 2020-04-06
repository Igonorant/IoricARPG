#include "animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::AddFrame(unsigned int texID, float duration)
{
	frames.emplace_back(texID, duration);
	totalDuration += duration;
}


void Animation::Update(float dt)
{
	if (!frames.empty())
	{
		timeCounter += dt;
		if (timeCounter / totalDuration > 1.0f)
		{
			currentFrame = 0;
		}

		float counter = (float)std::fmod(timeCounter, totalDuration);
		while ((counter - frames[currentFrame].duration) > 0)
		{
			counter -= frames[currentFrame].duration;
			currentFrame++;
		}
	}
}

unsigned int Animation::GetFrame()
{
	if (!frames.empty())
	{
		return frames[currentFrame].texID;
	}
}
