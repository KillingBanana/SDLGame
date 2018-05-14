#ifndef SDLGAME_COLLIDER_HPP
#define SDLGAME_COLLIDER_HPP

#include <string>
#include <SDL.h>
#include "ECS.hpp"
#include "Transform.hpp"

class Collider : public Component {
public:
	Vector2int offset, size;
	SDL_Rect rect;
	Collider(Entity *entity, int x, int y, int width, int height, std::string tag);

	void Start() override;
	void Update() override;
private:
	Transform *transform;
	std::string tag;
};

#endif //SDLGAME_COLLIDER_HPP
