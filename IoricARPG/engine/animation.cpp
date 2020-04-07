#include "animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::AddFrame(unsigned int texID, float duration)
{
	totalDuration += duration;
	frames.emplace_back(texID, totalDuration);
}


void Animation::Update(float dt)
{
	if (!frames.empty())
	{
		timeCounter += dt;
		if (timeCounter >= totalDuration)
		{
			timeCounter = (float)std::fmod(timeCounter, totalDuration);
			currentFrame = 0;
		}

		while (currentFrame < frames.size())
		{
			if (timeCounter > frames[currentFrame].durationFromBegin)
			{
				currentFrame++;
			}
			else
			{
				break;
			}
		}

	}
}

unsigned int Animation::GetFrame()
{
	if (!frames.empty())
	{
		return frames[currentFrame].texID;
	}
	else
	{
		return 0;
	}
}
