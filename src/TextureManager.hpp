#ifndef SDLGAME_TEXTUREMANAGER_HPP
#define SDLGAME_TEXTUREMANAGER_HPP

#include <SDL.h>

class TextureManager {
public:
	static SDL_Texture *LoadTexture(const char *filename);
	static void DrawTexture(SDL_Texture *texture, SDL_Rect *srcRect, SDL_Rect *dstRect);
};

#endif //SDLGAME_TEXTUREMANAGER_HPP
