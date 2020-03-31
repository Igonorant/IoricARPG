#include "engine\engine.h"

int main(int argc, char *argv[])
{
	Engine engine;

	if (!engine.Init())
	{
		engine.LoadTexture("assets/IoricToken.png");
		while (1)
		{
			engine.Display("assets/IoricToken.png");
		}
	}


	engine.Quit();
	return EXIT_SUCCESS;
}