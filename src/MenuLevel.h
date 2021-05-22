
#ifndef INKBALL_MENULEVEL_H
#define INKBALL_MENULEVEL_H

#include "Level.h"
#include "MenuItem.h"

#include <vector>


namespace Where1::InkBall {
	class MenuLevel : public Level {
	public:
		virtual void draw(SDL_Renderer *renderer) override;

		virtual void update(double timestep) override;

		virtual void handle_mouse_button(SDL_MouseButtonEvent &e) override;

		virtual bool is_menu() override;

	protected:
		virtual std::vector<MenuItem> get_menu_items() = 0;

		virtual Game &get_game() = 0;

	private:
		const int PADDING = 10;
		const int TEXT_SIZE = 30;

		SDL_Rect get_bounding_rect(MenuItem &item, int index);
	};
}


#endif //INKBALL_MENULEVEL_H
