#include "game.h"

Game::Game()
{
	if (!engine.Init())
	{
		state = State::Initialized;
	}
}

Game::~Game()
{
	engine.Quit();
}

void Game::HandleEvents()
{
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
		case SDL_QUIT:
			state = State::Quiting;
			break;
		case SDL_KEYDOWN:
			switch (events.key.keysym.sym)
			{
			case SDLK_RIGHT:
				
				break;
			case SDLK_LEFT:
				
				break;
			case SDLK_UP:
				
				break;
			case SDLK_DOWN:
				
				break;
			}
			break;
		}
	}
}

void Game::Update()
{
}

void Game::Render()
{
	engine.Display();

	engine.ClearBackgroundQueue();
	engine.ClearForegroundQueue();
}
