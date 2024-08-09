#include "header.h"
#include "Game.h"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	Game* game = new Game();
	
	game->run();

	delete game;

	return 0;
}