#include "Game.hpp"
#include "Clock.hpp"

int main(int argc, char *argv[]) {
	for (int i = 0; i < argc; ++i) std::cout << argv[i] << " ";
	std::cout << std::endl;

	Game *game = new Game();
	Clock clock = Clock();

	game->Init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, false);

	while (game->Running()) {
		clock.Tick();
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Clean();

	return 0;
}