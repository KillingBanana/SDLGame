#include "TextureManager.hpp"
#include "SDL_image.h"
#include "Game.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *filename) {
	if (filename == nullptr) return nullptr;

	SDL_Surface *tmp = IMG_Load(filename);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, tmp);
	SDL_FreeSurface(tmp);

	return texture;
}

void TextureManager::DrawTexture(SDL_Texture *texture, SDL_Rect *srcRect, SDL_Rect *dstRect) {
	SDL_RenderCopy(Game::renderer, texture, srcRect, dstRect);
}
