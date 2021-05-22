
#include "TextScreenLevel.h"
#include "Drawing.h"
#include "Game.h"

namespace Where1::InkBall {
	void TextScreenLevel::update(double timestep) {
		// nop
	}

	void TextScreenLevel::draw(SDL_Renderer *renderer) {
		SDL_SetRenderDrawColor(renderer, 230, 230, 230, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		const int PADDING = 10;

		const int SURTEXT_FONT_SIZE = 40;
		const int SUBTEXT_FONT_SIZE = 20;

		const std::string subtext = "Press ESC for menu";

		std::pair<int, int> surtext_size = SDL_Utilities::GetStringSize(surtext, SURTEXT_FONT_SIZE);

		int x = Game::WIDTH / 2 - surtext_size.first / 2;
		int y = (Game::HEIGHT - Game::TOP_BAR_HEIGHT) / 2 - surtext_size.second / 2;

		SDL_Rect rect{
				.x = x - PADDING,
				.y = y - PADDING,
				.w = surtext_size.first + 2 * PADDING,
				.h = surtext_size.second + 2 * PADDING,
		};

		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

		SDL_RenderFillRect(renderer, &rect);

		SDL_Rect subtext_rect{
				.x = rect.x,
				.y = rect.y + rect.h,
				.w = rect.w,
				.h = SDL_Utilities::GetStringSize(subtext, SUBTEXT_FONT_SIZE).second + 2 * PADDING,
		};

		SDL_RenderFillRect(renderer, &subtext_rect);

		SDL_Utilities::WriteText(renderer, {(double) x, (double) y}, surtext, SURTEXT_FONT_SIZE, 0, 0, 0);
		SDL_Utilities::WriteText(renderer, {(double) x, (double) subtext_rect.y + PADDING}, subtext, SUBTEXT_FONT_SIZE, 0, 0, 0);
	}

	TextScreenLevel::TextScreenLevel(std::string surtext)
			: surtext(surtext) {

	}

	bool TextScreenLevel::is_menu() {
		return false;
	}
}