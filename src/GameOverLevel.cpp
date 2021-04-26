
#include "GameOverLevel.h"

#include "Drawing.h"
#include "Game.h"

namespace Where1::InkBall {

	void GameOverLevel::update(double timestep) {
		// nop
	}

	void GameOverLevel::draw(SDL_Renderer *renderer) {
		int PADDING = 10;

		std::string message = "GAME OVER";
		int size = 40;

		std::pair<int, int> message_size = SDL_Utilities::GetStringSize(message, size);

		int x = Game::WIDTH / 2 - message_size.first / 2;
		int y = (Game::HEIGHT - Game::TOP_BAR_HEIGHT)/ 2 - message_size.second / 2;

		SDL_Rect rect{
				.x = x - PADDING,
				.y = y - PADDING,
				.w = message_size.first + 2 * PADDING,
				.h = message_size.second + 2 * PADDING,
		};

		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

		SDL_RenderFillRect(renderer, &rect);

		SDL_Utilities::WriteText(renderer, {(double)x, (double)y}, message, size, 0, 0, 0);
	}
}