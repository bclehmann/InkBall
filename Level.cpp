
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
		for (auto &ball : balls) {
			ball.update(timestep);

			Geometry::Line<double> l(Geometry::Vector2<double>(50, 0), Geometry::Vector2<double>(50, 5000));
			if(ball.collides_with(l)){
				ball.reflect(Geometry::Vector2<double>(0, 1));
			}

		}
	}

	Level::Level(std::vector<Ball> balls, std::vector<Block> blocks)
			: balls(balls), blocks(blocks) {

	}
}