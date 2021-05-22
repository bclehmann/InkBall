
#include <filesystem>
#include <iostream>
#include "LevelSelectMenu.h"

namespace Where1::InkBall {

	LevelSelectMenu::LevelSelectMenu(Game &game)
			: game(game) {

	}

	Game &LevelSelectMenu::get_game() {
		return game;
	}

	std::vector<MenuItem> LevelSelectMenu::get_menu_items() {
		std::vector<MenuItem> items;

		for (const auto &entry : std::filesystem::directory_iterator(std::filesystem::path(game.get_level_path_prefix()))) {
			items.push_back(MenuItem{
					.text = entry.path().stem().string(),
					.on_click = [path = entry.path().string()](Game &game) { // Cannot capture path by ref because it won't exist when this lambda is called
						game.load_level_from_path(path);
					}
			});
		}

		return items;
	}
}
