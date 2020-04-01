#include "engine.h"

int Engine::Init()
{
	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		LogSDLError(std::cout, "SDL_Init");
		return 1;
	}

	// Create window
	window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		LogSDLError(std::cout, "SDL_CreateWindow");
		return 1;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		LogSDLError(std::cout, "SDL_CreateRenderer");
		return 1;
	}

	// Set Texture Codex renderer
	textures.SetRenderer(renderer);

	return 0;
}

int Engine::Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

unsigned int Engine::LoadTexture(const char* path)
{
	return textures.LoadTexture(path);
}

void Engine::RenderTexture(const unsigned int ID, int x, int y, float scale)
{
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_Texture* tex = textures.GetTexture(ID);
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	dst.w = (int)(dst.w * scale);
	dst.h = (int)(dst.h * scale);
	SDL_RenderCopy(renderer, tex, NULL, &dst);
}

void Engine::ClearBackgroundQueue()
{
	background_queue.clear();
}

void Engine::ClearForegroundQueue()
{
	foreground_queue.clear();
}

void Engine::PushBackgroundQueue(unsigned int ID, unsigned int xpos, unsigned int ypos, float scale)
{
	background_queue.emplace_back(ID, xpos, ypos, scale);
}

void Engine::PushForegroundQueue(unsigned int ID, unsigned int xpos, unsigned int ypos, float scale)
{
	foreground_queue.emplace_back(ID, xpos, ypos, scale);
}

void Engine::Display()
{
	// First clear the renderer
	SDL_RenderClear(renderer);

	// Draw background
	for (auto obj : background_queue)
	{
		RenderTexture(obj.textureID, obj.xpos, obj.ypos, obj.scale);
	}

	// Draw foreground
	for (auto obj : foreground_queue)
	{
		RenderTexture(obj.textureID, obj.xpos, obj.ypos, obj.scale);
	}

	// Update the screen
	SDL_RenderPresent(renderer);

	// Take a quick break after all that hard work
	// SDL_Delay(1000);

}
