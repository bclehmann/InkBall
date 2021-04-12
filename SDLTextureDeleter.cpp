
#include "SDLTextureDeleter.h"

void SDLTextureDeleter::operator()(SDL_Texture *texture) {
	if(texture != nullptr)
		SDL_DestroyTexture(texture);
}
