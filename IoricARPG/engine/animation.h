#pragma once

#include <vector>
#include <cmath>
#include <algorithm>

#include <SDL.h>

class Animation
{
public:
	Animation();
	~Animation();

	void AddFrame(unsigned int texID, float duration);

	void Update(float dt);

	unsigned int GetFrame();

private:
	struct Frame
	{
		Frame(unsigned int texID, float durationFromBegin)
			:texID(texID), durationFromBegin(durationFromBegin)
		{

		}
		unsigned int texID;
		float durationFromBegin;
	};

private:
	unsigned int currentFrame = 0;
	std::vector<Frame> frames;
	float timeCounter = 0;
	float totalDuration = 0;
};