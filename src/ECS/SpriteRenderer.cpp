
#include "SpriteRenderer.hpp"
#include "../TextureManager.hpp"

SpriteRenderer::SpriteRenderer(Entity *entity, int x, int y, int width, int height, const char *sprite) : Component(entity), offset(x, y), size(width, height) {
	SetSprite(sprite);
}

SpriteRenderer::~SpriteRenderer() {
	SDL_DestroyTexture(texture);
}

void SpriteRenderer::Start() {
	transform = entity->GetComponent<Transform>();

	srcRect = {0, 0, size.x, size.y};
}

void SpriteRenderer::Update() {
	dstRect.w = size.x;
	dstRect.h = size.y;

	dstRect.x = transform->X() - dstRect.w / 2 + offset.x;
	dstRect.y = transform->Y() - dstRect.h / 2 + offset.y;
}

void SpriteRenderer::Draw() {
	TextureManager::DrawTexture(texture, &srcRect, &dstRect);
}

void SpriteRenderer::SetSprite(const char *path) {
	texture = TextureManager::LoadTexture(path);
}
