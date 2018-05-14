#include "Tile.hpp"

const int Tile::TILE_SIZE = 64;

Tile::Tile(Entity *entity, int x, int y, int id) : Component(entity), id(id) {
	transform = entity->AddComponent<Transform>(x * TILE_SIZE, y * TILE_SIZE);
	spriteRenderer = entity->AddComponent<SpriteRenderer>(0, 0, 64, 64, GetPath(id));
}

const char *Tile::GetPath(int id) {
	switch (id) {
		case 0:
			return "../img/tiles/water.png";
		case 1:
			return "../img/tiles/grass.png";
		case 2:
			return "../img/tiles/dirt.png";
		default:
			return nullptr;
	}
}
