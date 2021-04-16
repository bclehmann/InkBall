
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

		for(auto &curr : inktrails){
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			curr.draw(renderer);
		}
	}

	void Level::update(double timestep) {
		for (auto &ball : balls) {
			ball.update(timestep);

//			Geometry::Line<double> l1(Geometry::Vector2<double>(50, 0), Geometry::Vector2<double>(50, 5000));
//			Geometry::Line<double> l2(Geometry::Vector2<double>(0, 0), Geometry::Vector2<double>(5000, 0));
//			Geometry::Line<double> l3(Geometry::Vector2<double>(0, 0), Geometry::Vector2<double>(0, 5000));
//			Geometry::Line<double> l4(Geometry::Vector2<double>(0, 200), Geometry::Vector2<double>(50, 200));
//			if (ball.collides_with(l1) || ball.collides_with(l3)) {
//				ball.reflect(Geometry::Vector2<double>(0, 1));
//			}
//
//			if (ball.collides_with(l2) || ball.collides_with(l4)) {
//				ball.reflect(Geometry::Vector2<double>(1, 0));
//			}

			for(auto &block : blocks){
				ball.reflect_if_collides_with(block);
			}

		}
	}

	Level::Level(std::vector<Ball> balls, std::vector<Block> blocks)
			: balls(balls), blocks(blocks) {

	}

	void Level::handle_mouse_move(SDL_MouseMotionEvent &e) {
		bool left_mouse_down = e.state & SDL_BUTTON_LMASK;

		if (left_mouse_down) {
			if (!is_drawing_trail) {
				is_drawing_trail = true;
				inktrails.emplace_back();
				current_trail = inktrails.end();
				current_trail--;
			}

			current_trail->append(Geometry::Vector2<double>(e.x, e.y));
		} else {
			is_drawing_trail = false;
		}
	}
}