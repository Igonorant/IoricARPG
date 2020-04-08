#pragma once

#include "../engine/engine.h"
#include "object.h"
#include "player.h"
#include "../engine/animation.h"

#include <algorithm>
#include <vector>
#include <SDL.h>

class Game
{
public:
	enum State
	{
		NotInitialized = 0,
		Initialized,
		Running,
		Paused,
		Quiting
	};
public:
	Game();
	~Game();

	// Loading methods

	// Game loop methods
	void HandleEvents();
	void Update();
	void Render();

	inline State& GetState()
	{
		return state;
	}

private:
	State state = State::NotInitialized;
	Engine engine;
	SDL_Event events;

	Player player;
	float dt;
	Uint32 lastTick;


public:
	Animation testAnimation;
	unsigned int fireballTexID[3];
	std::vector<Object> objects;
};