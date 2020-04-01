#include "engine\engine.h"

int main(int argc, char *argv[])
{
	Engine engine;

	if (!engine.Init())
	{
		// Texture loading
		unsigned int foreID = engine.LoadTexture("assets/IoricToken.png");

		int x = 0;
		int y = 0;
		float speed = 10.5f;

		SDL_Event e;
		bool quit = false;
		while (!quit) {
			// Event pooling
			while (SDL_PollEvent(&e))
			{
				switch (e.type)
				{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym)
					{
					case SDLK_RIGHT:
						x = (int)(x + speed);
						break;
					case SDLK_LEFT:
						x = (int)(x - speed);
						break;
					case SDLK_UP:
						y = (int)(y - speed);
						break;
					case SDLK_DOWN:
						y = (int)(y + speed);
						break;
					}
					break;

				}

			}


			// Rendering
			engine.PushForegroundQueue(foreID, x, y, 1.0f);

			engine.Display();

			engine.ClearBackgroundQueue();
			engine.ClearForegroundQueue();

		}
	}

	engine.Quit();
	return EXIT_SUCCESS;
}