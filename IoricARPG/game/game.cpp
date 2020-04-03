#include "game.h"

Game::Game()
{
	if (!engine.Init())
	{
		state = State::Initialized;

		// Load player assets and set position on screen
		player.pos.x = 200.0f;
		player.pos.y = 200.0f;
		player.texID = engine.LoadTexture("assets/IoricToken.png");
		player.scale = 1.0f;
		player.vel.x = 0.0f;
		player.vel.y = 0.0f;
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
				player.vel.x += 10.0f;
				break;
			case SDLK_LEFT:
				player.vel.x -= 10.0f;
				break;
			case SDLK_UP:
				player.vel.y -= 10.0f;
				break;
			case SDLK_DOWN:
				player.vel.y += 10.0f;
				break;
			case SDLK_SPACE:
				player.vel.x = 0.0f;
				player.vel.y = 0.0f;
				break;
			}
			break;

		}
	}
}

void Game::Update()
{
	dt = (float)(SDL_GetTicks() - lastTick)/1000;

	player.Update(dt);

	lastTick = SDL_GetTicks();
}

void Game::Render()
{
	engine.PushForegroundQueue(player);

	engine.Display();

	engine.ClearBackgroundQueue();
	engine.ClearForegroundQueue();
}
