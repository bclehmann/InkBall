
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

			for(auto &block : blocks){
				ball.reflect_if_collides_with(block);
			}

			for(auto it = inktrails.begin(); it != inktrails.end(); it++){
				if(ball.reflect_if_collides_with(*it)){
					inktrails.erase(it);
					break; // To avoid reading invalidated references we only let it collide once per update
				}
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
				last_flushed_point = Geometry::Vector2<double>(e.x, e.y);
				current_trail->append(last_flushed_point);
			}else if(hypot(last_flushed_point.x - e.x, last_flushed_point.y - e.y) >= MIN_DRAG_DISTANCE){
				last_flushed_point = Geometry::Vector2<double>(e.x, e.y);
				current_trail->append(last_flushed_point);
			}
		} else {
			is_drawing_trail = false;
		}
	}
}