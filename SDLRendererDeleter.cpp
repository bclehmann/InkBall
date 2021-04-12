
#include "SDLRendererDeleter.h"

void SDLRendererDeleter::operator()(SDL_Renderer *renderer) {
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);
}
