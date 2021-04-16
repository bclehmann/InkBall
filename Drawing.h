
#ifndef INKBALL_DRAWING_H
#define INKBALL_DRAWING_H

#include "SDLError.h"
#include "Vector2.h"
#include "Line.h"

#include <SDL2/SDL.h>
#include <cmath>

namespace Where1::SDL_Utilities{
	void DrawCircle(SDL_Renderer *renderer, int centre_x, int y, int r);
	void DrawLine(SDL_Renderer *renderer, Geometry::Vector2<double> p1, Geometry::Vector2<double> p2, int thickness);
	void DrawLine(SDL_Renderer *renderer, Geometry::Line<double> line, int thickness);
}

#endif //INKBALL_DRAWING_H
