#include "game.h"

Game::Game()
{
	dt = 0.001f;
	lastTick = 0;

	if (!engine.Init())
	{
		state = State::Initialized;

		// Load player assets and set position on screen
		player.pos.x = 200.0f;
		player.pos.y = 200.0f;
		player.AddAnimationFrame(Object::State::Idle, engine.LoadTexture("assets/main_character/moving_down_00.png"), 1.0f);
		player.scale = 1.0f;
		player.vel.x = 0.0f;
		player.vel.y = 0.0f;
		player.SetState(Object::State::Idle);

		player.AddAnimationFrame(Object::State::MovingRight, engine.LoadTexture("assets/main_character/moving_right_00.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingRight, engine.LoadTexture("assets/main_character/moving_right_01.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingRight, engine.LoadTexture("assets/main_character/moving_right_02.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingRight, engine.LoadTexture("assets/main_character/moving_right_03.png"), 0.3f);

		player.AddAnimationFrame(Object::State::MovingLeft, engine.LoadTexture("assets/main_character/moving_left_01.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingLeft, engine.LoadTexture("assets/main_character/moving_left_02.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingLeft, engine.LoadTexture("assets/main_character/moving_left_00.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingLeft, engine.LoadTexture("assets/main_character/moving_left_03.png"), 0.3f);

		player.AddAnimationFrame(Object::State::MovingUp, engine.LoadTexture("assets/main_character/moving_up_00.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingUp, engine.LoadTexture("assets/main_character/moving_up_01.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingUp, engine.LoadTexture("assets/main_character/moving_up_02.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingUp, engine.LoadTexture("assets/main_character/moving_up_03.png"), 0.3f);

		player.AddAnimationFrame(Object::State::MovingDown, engine.LoadTexture("assets/main_character/moving_down_00.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingDown, engine.LoadTexture("assets/main_character/moving_down_01.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingDown, engine.LoadTexture("assets/main_character/moving_down_02.png"), 0.3f);
		player.AddAnimationFrame(Object::State::MovingDown, engine.LoadTexture("assets/main_character/moving_down_03.png"), 0.3f);

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
				player.vel.x += 5.0f;
				player.vel.x = std::max(player.vel.x, 15.0f);
				player.SetState(Object::State::MovingRight);
				break;
			case SDLK_LEFT:
				player.vel.x -= 5.0f;
				player.vel.x = std::min(player.vel.x, -15.0f);
				player.SetState(Object::State::MovingLeft);
				break;
			case SDLK_UP:
				player.vel.y -= 5.0f;
				player.vel.y = std::min(player.vel.y, -15.0f);
				player.SetState(Object::State::MovingUp);
				break;
			case SDLK_DOWN:
				player.vel.y += 5.0f;
				player.vel.y = std::max(player.vel.y, 15.0f);
				player.SetState(Object::State::MovingDown);
				break;
			case SDLK_SPACE:
				player.vel.x = 0.0f;
				player.vel.y = 0.0f;
				player.SetState(Object::State::Idle);
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
