#include "Game.hpp"
#include "ECS/Components.hpp"
#include <sstream>

bool Game::debug = false;

SDL_Renderer *Game::renderer = nullptr;

SDL_Event Game::event;

std::vector<Collider *> Game::colliders;

Manager Game::manager;

Game::Game() : player(manager.AddEntity("Player")) {}

Game::~Game() = default;

void Game::Init(const char *title, int x, int y, int width, int height, bool fullscreen) {
	std::cout << "Starting game initialization" << std::endl;

	isRunning = false;
	window = nullptr;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "SDL not initialized, SDL Error: " << SDL_GetError() << std::endl;
		return;
	}

	unsigned int flags = SDL_WINDOW_SHOWN;

	if (fullscreen) {
		flags |= SDL_WINDOW_FULLSCREEN;

		SDL_DisplayMode displayMode;
		if (SDL_GetDesktopDisplayMode(0, &displayMode) == 0) {
			width = displayMode.w;
			height = displayMode.h;
		} else {
			std::cerr << "Error while trying to set fullscreen resolution: " << SDL_GetError() << std::endl;
			return;
		}
	}

	window = SDL_CreateWindow(title, x, y, width, height, flags);
	if (!window) {
		std::cerr << "Window not created, SDL Error: " << SDL_GetError() << std::endl;
		return;
	}

	Game::renderer = SDL_CreateRenderer(window, -1, 0);
	if (!Game::renderer) {
		std::cerr << "Renderer not created, SDL Error:" << SDL_GetError() << std::endl;
		return;
	}
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);

	Map::Load("../assets/map");

	player.AddComponent<Transform>(64, 128);
	player.AddComponent<SpriteRenderer>(0, -31, 64, 64, "../img/player/idle.png");
	player.AddComponent<KeyboardController>();
	player.AddComponent<Collider>(0, 0, 20, 1, "Feet");
	player.AddComponent<Collider>(0, -30, 20, 60, "Body");

	isRunning = true;

	std::cout << "Game initialized successfully" << std::endl;
}

void Game::HandleEvents() {
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::Update() {
	manager.Refresh();
	manager.Update();
}

void Game::Render() {
	SDL_RenderClear(Game::renderer);
	manager.Draw();
	player.Draw();

	if (debug) {
		for (auto collider:colliders) SDL_RenderDrawRect(renderer, &collider->rect);

		int x = player.GetComponent<Transform>()->X(), y = player.GetComponent<Transform>()->Y();
		SDL_RenderDrawLine(renderer, x, 0, x, 640);
		SDL_RenderDrawLine(renderer, 0, y, 640, y);
	}
	SDL_RenderPresent(Game::renderer);
}

void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Game::renderer);
	SDL_Quit();
	std::cout << "Game Quit" << std::endl;
}

void Game::AddTile(int x, int y, int id) {
	auto &tile = manager.AddEntity("Tile");
	tile.AddComponent<Tile>(x, y, id);
}
