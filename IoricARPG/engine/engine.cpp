#include "engine.h"

int Engine::Init()
{
	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Create window
	window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Set Texture Codex renderer
	textures.SetRenderer(renderer);

	return 0;
}

int Engine::Quit()
{
	SDL_Quit();
	return 0;
}

unsigned int Engine::LoadTexture(const char* path)
{
	return textures.LoadTexture(path);
}

void Engine::Display(const char* path)
{
	//First clear the renderer
	SDL_RenderClear(renderer);
	//Draw the texture
	SDL_RenderCopy(renderer, textures.GetTexture(path), NULL, NULL);
	//Update the screen
	SDL_RenderPresent(renderer);
	//Take a quick break after all that hard work
	SDL_Delay(1000);

	
}
