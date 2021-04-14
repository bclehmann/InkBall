
#include "Level.h"

namespace Where1::InkBall {
	void Level::draw(SDL_Renderer *renderer) {
		SDL_SetRenderDrawColor(renderer, 230, 230, 230, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		for (auto &curr : blocks) {
			curr.draw(renderer);
		}

		for (auto &curr : balls) {
			curr.draw(renderer);
		}
	}

	void Level::update(double timestep) {
		for (auto &curr : balls) {
			curr.update(timestep);
		}
	}

	Level::Level(std::vector<Ball> balls, std::vector<Block> blocks)
			: balls(balls), blocks(blocks) {

	}
}