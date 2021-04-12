#include "SDL2/SDL.h"

#ifndef INKBALL_SDLWINDOWDELETER_H
#define INKBALL_SDLWINDOWDELETER_H


namespace Where1::SDL_Utilities {
	class SDLWindowDeleter {
	public:
		void operator()(SDL_Window *window);
	};
}

#endif //INKBALL_SDLWINDOWDELETER_H
