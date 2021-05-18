
#include "EscapeMenu.h"

namespace Where1::InkBall {

	std::vector<MenuItem> EscapeMenu::get_menu_items() {
		return // No clue why autoformat butchered it like this....
				{
						MenuItem{
								.text = "Quit",
								.on_click = [](Game &game) {
									game.quit();
								}
						}
				};
	}

	EscapeMenu::EscapeMenu(Game &game)
			: game(game) {

	}

	Game &EscapeMenu::get_game() {
		return game;
	}
}
