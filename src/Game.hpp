#ifndef SDLGAME_GAME_H
#define SDLGAME_GAME_H

#include <iostream>
#include <SDL.h>
#include "Map.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Components.hpp"

class Game {
public:
	static bool debug;
	Game();

	~Game();

	void Init(const char *title, int x, int y, int width, int height, bool fullscreen);

	void HandleEvents();

	void Update();

	void Render();

	void Clean();

	bool Running() { return isRunning; }

	static void AddTile(int x, int y, int id);

	static SDL_Renderer *renderer;
	static SDL_Event event;
	static std::vector<Collider *> colliders;

private:
	bool isRunning;

	SDL_Window *window;

	static Manager manager;

	Entity &player;
};

#endif //SDLGAME_GAME_H
