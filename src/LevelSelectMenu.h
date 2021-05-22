
#ifndef INKBALL_LEVELSELECTMENU_H
#define INKBALL_LEVELSELECTMENU_H

#include "MenuLevel.h"

namespace Where1::InkBall {
	class LevelSelectMenu : public MenuLevel {
	public:
		explicit LevelSelectMenu(Game &game);

		virtual std::vector<MenuItem> get_menu_items() override;

		virtual Game &get_game() override;

	private:
		Game &game;
	};
}

#endif //INKBALL_LEVELSELECTMENU_H
