
#include "SDLWindowDeleter.h"

void SDLWindowDeleter::operator()(SDL_Window *window) {
	if (window != nullptr)
		SDL_DestroyWindow(window);
}
