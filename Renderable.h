
#ifndef INKBALL_RENDERABLE_H
#define INKBALL_RENDERABLE_H

#include <SDL2/SDL.h>

namespace Where1::InkBall{
	class Renderable{
	public:
		virtual void draw(SDL_Renderer *renderer) = 0;
	};
}

#endif //INKBALL_RENDERABLE_H
