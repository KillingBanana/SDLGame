#include "KeyboardController.hpp"
#include "../Game.hpp"

KeyboardController::KeyboardController(Entity *entity) : Component(entity) {}

void KeyboardController::Start() {
	transform = entity->GetComponent<Transform>();
}

void KeyboardController::Update() {
	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym) {
			case SDLK_UP:
			case SDLK_w:
				transform->velocity.y = -speed;
				break;
			case SDLK_DOWN:
			case SDLK_s:
				transform->velocity.y = speed;
				break;
			case SDLK_LEFT:
			case SDLK_a:
				transform->velocity.x = -speed;
				break;
			case SDLK_RIGHT:
			case SDLK_d:
				transform->velocity.x = speed;
				break;
			default:
				break;
		}
	}
	if (Game::event.type == SDL_KEYUP) {
		switch (Game::event.key.keysym.sym) {
			case SDLK_UP:
			case SDLK_DOWN:
			case SDLK_w:
			case SDLK_s:
				transform->velocity.y = 0;
				break;
			case SDLK_LEFT:
			case SDLK_RIGHT:
			case SDLK_a:
			case SDLK_d:
				transform->velocity.x = 0;
				break;
			default:
				break;
		}
	}
}