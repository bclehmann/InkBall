
#ifndef INKBALL_SDLTEXTUREDELETER_H
#define INKBALL_SDLTEXTUREDELETER_H


#include <SDL.h>

namespace Where1::SDL_Utilities {
	class SDLTextureDeleter {
	public:
		void operator()(SDL_Texture *texture);
	};
}

#endif //INKBALL_SDLTEXTUREDELETER_H
