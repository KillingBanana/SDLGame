#ifndef SDLGAME_TILE_HPP
#define SDLGAME_TILE_HPP

#include <SDL.h>
#include "ECS.hpp"
#include "Transform.hpp"
#include "SpriteRenderer.hpp"

class Tile : public Component {
public:
	static const int TILE_SIZE;

	Tile(Entity *entity, int x, int y, int id);

	static const char *GetPath(int id);

	int id;
private:
	Transform *transform;
	SpriteRenderer *spriteRenderer;
};

#endif //SDLGAME_TILE_HPP
