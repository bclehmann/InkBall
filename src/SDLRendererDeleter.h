
#ifndef INKBALL_SDLRENDERERDELETER_H
#define INKBALL_SDLRENDERERDELETER_H


#include <SDL.h>

namespace Where1::SDL_Utilities {
	class SDLRendererDeleter {
	public:
		void operator()(SDL_Renderer *renderer);
	};
}

#endif //INKBALL_SDLRENDERERDELETER_H
