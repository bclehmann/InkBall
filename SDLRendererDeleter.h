
#ifndef INKBALL_SDLRENDERERDELETER_H
#define INKBALL_SDLRENDERERDELETER_H


#include <SDL2/SDL.h>

class SDLRendererDeleter {
public:
	void operator()(SDL_Renderer *renderer);
};


#endif //INKBALL_SDLRENDERERDELETER_H
