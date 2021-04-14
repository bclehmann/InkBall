
#ifndef INKBALL_DRAWING_H
#define INKBALL_DRAWING_H

#include "SDLError.h"

#include <SDL2/SDL.h>
#include <cmath>

namespace Where1::SDL_Utilities{
	void DrawCircle(SDL_Renderer *renderer, int centre_x, int y, int r);
}

#endif //INKBALL_DRAWING_H
