
#ifndef INKBALL_LEVEL_H
#define INKBALL_LEVEL_H

#include "Renderable.h"
#include "Updatable.h"

namespace Where1::InkBall {
	class Level : public Renderable, public Updatable {
	public:
		virtual void handle_mouse_move(SDL_MouseMotionEvent &e);
		virtual void handle_mouse_button(SDL_MouseButtonEvent &e);
		virtual bool is_menu() = 0;
	};
}


#endif //INKBALL_LEVEL_H
