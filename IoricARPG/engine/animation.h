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
	void AddFrame(unsigned int texID, float duration, float scale);

	void Update(float dt);

	unsigned int GetFrame();
	float GetScale();

private:
	struct Frame
	{
		Frame(unsigned int texID, float durationFromBegin)
			:texID(texID), durationFromBegin(durationFromBegin)
		{
			scale = 1.0f;
		}
		Frame(unsigned int texID, float durationFromBegin, float scale)
			:texID(texID), durationFromBegin(durationFromBegin), scale(scale)
		{

		}
		unsigned int texID;
		float durationFromBegin;
		float scale;
	};

private:
	unsigned int currentFrame = 0;
	std::vector<Frame> frames;
	float timeCounter = 0;
	float totalDuration = 0;
};