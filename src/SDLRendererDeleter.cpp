
#include "SDLRendererDeleter.h"

namespace Where1::SDL_Utilities {
	void SDLRendererDeleter::operator()(SDL_Renderer *renderer) {
		if (renderer != nullptr)
			SDL_DestroyRenderer(renderer);
	}
}