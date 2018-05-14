#ifndef SDLGAME_SPRITECOMPONENT_HPP
#define SDLGAME_SPRITECOMPONENT_HPP

#include "ECS.hpp"
#include <SDL.h>
#include <windef.h>
#include "Transform.hpp"

class SpriteRenderer : public Component {
public:
	Vector2int size, offset;
	SpriteRenderer(Entity *entity, int x, int y, int width, int height, const char *sprite);
	~SpriteRenderer() override;

	void Start() override;
	void Update() override;
	void Draw() override;

	void SetSprite(const char *path);
private:

	Transform *transform = nullptr;
	SDL_Texture *texture = nullptr;
	SDL_Rect srcRect, dstRect;
};

#endif //SDLGAME_SPRITECOMPONENT_HPP
