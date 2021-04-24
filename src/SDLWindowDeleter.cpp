
#include "SDLWindowDeleter.h"


namespace Where1::SDL_Utilities {
	void SDLWindowDeleter::operator()(SDL_Window *window) {
		if (window != nullptr)
			SDL_DestroyWindow(window);
	}
}
