#pragma once

#include "..\engine\engine.h"
#include "object.h"

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
};