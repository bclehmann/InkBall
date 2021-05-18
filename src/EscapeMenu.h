
#ifndef INKBALL_ESCAPEMENU_H
#define INKBALL_ESCAPEMENU_H

#include "MenuLevel.h"

namespace Where1::InkBall {
	class EscapeMenu : public MenuLevel {
	public:
		explicit EscapeMenu(Game &game);

		virtual std::vector<MenuItem> get_menu_items() override;

		virtual Game &get_game() override;

	private:
		Game &game;
	};
}


#endif //INKBALL_ESCAPEMENU_H
