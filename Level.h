
#ifndef INKBALL_LEVEL_H
#define INKBALL_LEVEL_H

#include "Ball.h"
#include "Block.h"

#include <vector>

namespace Where1::InkBall {
	class Level : public Renderable, public Updatable {
	public:
		Level() = default;
		Level(std::vector<Ball> balls, std::vector<Block> blocks);
		std::vector<Ball> balls;
		std::vector<Block> blocks;

		void draw(SDL_Renderer *renderer) override;
		void update(double timestep) override;
	};
}

#endif //INKBALL_LEVEL_H
