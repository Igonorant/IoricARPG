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

		fireballTexID[0] = engine.LoadTexture("assets/ground_fire_frame1.png");
		fireballTexID[1] = engine.LoadTexture("assets/ground_fire_frame2.png");
		fireballTexID[2] = engine.LoadTexture("assets/ground_fire_frame3.png");

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
			case SDLK_q:
				objects.emplace_back(0, player.pos.x, player.pos.y, 1.0f);
				objects.back().AddAnimationFrame(Object::State::Moving, fireballTexID[0], 0.1f);
				objects.back().AddAnimationFrame(Object::State::Moving, fireballTexID[1], 0.1f);
				objects.back().AddAnimationFrame(Object::State::Moving, fireballTexID[2], 0.1f);
		
				if (player.vel.x > 0.0f)
				{
					objects.back().vel.x = 90.0f;
				}
				else
				{
					objects.back().vel.x = -90.0f;
				}
				objects.back().vel.y = player.vel.y;

				objects.back().SetState(Object::State::Moving);
				objects.back().SetLifeSpan(2.0f);
				
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

	for (unsigned int i = 0; i < objects.size(); i++)
	{
		objects[i].Update(dt);
	}

	//remove all objects marked for deletion
	objects.erase(
		std::remove_if(objects.begin(),
			objects.end(),
			[](Object& i) {return i.GetState() == Object::State::MarkedForDeletion; }
		),	
		objects.end());


	lastTick = SDL_GetTicks();
}

void Game::Render()
{
	engine.PushForegroundQueue(player);
	if (!objects.empty())
	{
		for (unsigned int i = 0; i<objects.size();i++ )
		{
			engine.PushForegroundQueue(objects[i]);
		}
	}

	engine.Display();

	engine.ClearBackgroundQueue();
	engine.ClearForegroundQueue();
}
