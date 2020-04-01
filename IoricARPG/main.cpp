#include "game\game.h"

int main(int argc, char *argv[])
{
	Game game;

	while (game.GetState() != Game::State::Quiting)
	{
		game.HandleEvents();
		game.Update();
		game.Render();
	}

	return EXIT_SUCCESS;
}