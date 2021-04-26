
#ifndef INKBALL_LEVEL_H
#define INKBALL_LEVEL_H

#include "Ball.h"
#include "Block.h"
#include "InkTrail.h"
#include "Pocket.h"
#include "Game.h"

#include <vector>
#include <list>


namespace Where1::InkBall {
	class Game;

	class Level : public Renderable, public Updatable {
	public:
		Level(std::vector<Ball> balls, std::vector<Block> blocks, std::vector<Pocket> pockets, Game &game);

		std::vector<Ball> balls;
		std::vector<Block> blocks;
		std::vector<Pocket> pockets;

		void draw(SDL_Renderer *renderer) override;

		void update(double timestep) override;

		void handle_mouse_move(SDL_MouseMotionEvent &e);

	private:
		bool is_drawing_trail;
		bool valid_iterator = false;
		std::list<InkTrail> inktrails;
		std::list<InkTrail>::iterator current_trail;
		Geometry::Vector2<double> last_flushed_point{0, 0};
		int score = 0;
		Game &game;

		static constexpr const double MIN_DRAG_DISTANCE = 10;
	};
}

#endif //INKBALL_LEVEL_H
