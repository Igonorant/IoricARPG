#include "engine\engine.h"

int main(int argc, char *argv[])
{
	Engine engine;

	if (!engine.Init())
	{
		int count = 0;
		while (count < 10) {
			unsigned int foreID = engine.LoadTexture("assets/IoricToken.png");
			unsigned int backID = engine.LoadTexture("assets/Beltir Token.png");

			engine.ClearBackgroundQueue();
			engine.ClearForegroundQueue();

			engine.PushBackgroundQueue(backID, count*2, count * 2, 1.0f);
			engine.PushForegroundQueue(foreID, count * 1, count * 1, 1.0f);
			engine.PushForegroundQueue(foreID, count * 3, count * 3, 0.5f);
			engine.PushForegroundQueue(foreID, count * 30, count * 10, 2.0f);

			engine.Display();
			count++;
		}
	}

	engine.Quit();
	return EXIT_SUCCESS;
}