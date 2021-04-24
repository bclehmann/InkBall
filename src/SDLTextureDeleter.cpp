
#include "SDLTextureDeleter.h"

namespace Where1::SDL_Utilities {
	void SDLTextureDeleter::operator()(SDL_Texture *texture) {
		if (texture != nullptr)
			SDL_DestroyTexture(texture);
	}
}