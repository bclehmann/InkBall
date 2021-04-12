
#ifndef INKBALL_SDLTEXTUREDELETER_H
#define INKBALL_SDLTEXTUREDELETER_H


#include <SDL2/SDL.h>

class SDLTextureDeleter {
public:
	void operator()(SDL_Texture *texture);
};


#endif //INKBALL_SDLTEXTUREDELETER_H
