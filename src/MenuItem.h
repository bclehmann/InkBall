
#ifndef INKBALL_MENUITEM_H
#define INKBALL_MENUITEM_H

#include <string>
#include <functional>

#include "Game.h"

namespace Where1::InkBall {
	struct MenuItem {
		std::string text;
		std::function<void(Game &game)> on_click;
	};
}

#endif //INKBALL_MENUITEM_H
