
#include <sstream>
#include "PlayableLevel.h"

#include "Color.h"

namespace Where1::InkBall {

	bool are_colors_compatible(Color color1, Color color2) {
		return color1 == color2 || color1 == Color::Grey || color2 == Color::Grey;
	}

	void PlayableLevel::draw(SDL_Renderer *renderer) {
		SDL_SetRenderDrawColor(renderer, 230, 230, 230, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		for (auto &curr : blocks) {
			curr.draw(renderer);
		}

		for (auto &curr : pockets) {
			curr.draw(renderer);
		}

		for (auto &curr : balls) {
			curr.draw(renderer);
		}

		for (auto &curr : inktrails) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			curr.draw(renderer);
		}

		std::stringstream score_text_stream;
		score_text_stream << "Score: " << score;
		SDL_Utilities::WriteText(renderer, {0, 0}, score_text_stream.str(), Game::TOP_BAR_HEIGHT - 4, 0, 0, 0);
	}

	void PlayableLevel::update(double timestep) {
		bool unremoved_ball_exists = false;

		for (auto &ball : balls) {
			if(ball.is_removed()){
				continue;
			}else{
				unremoved_ball_exists = true;
			}

			ball.update(timestep);

			for (auto &block : blocks) {
				ball.reflect_if_collides_with(block);
			}

			for (auto &pocket : pockets) {
				if (ball.collides_with(pocket)) {
					if (are_colors_compatible(ball.color, pocket.color)) {
						ball.remove();

						if (ball.color == pocket.color) {
							score += 100;
						}
					} else {
						game.lose();
					}
				}
			}

			for (auto it = inktrails.begin(); it != inktrails.end(); it++) {
				if (ball.reflect_if_collides_with(*it)) {
					inktrails.erase(it);
					valid_iterator = false;
					break; // To avoid reading invalidated references we only let it collide once per update
				}
			}
		}

		if(!unremoved_ball_exists){
			game.win();
		}
	}

	PlayableLevel::PlayableLevel(std::vector<Ball> balls, std::vector<Block> blocks, std::vector<Pocket> pockets, Game &game)
			: balls(balls), blocks(blocks), pockets(pockets), game(game) {

	}

	void PlayableLevel::handle_mouse_move(SDL_MouseMotionEvent &e) {
		bool left_mouse_down = e.state & SDL_BUTTON_LMASK;

		if (left_mouse_down) {
			if (!is_drawing_trail || !valid_iterator) {
				is_drawing_trail = true;
				valid_iterator = true;
				inktrails.emplace_back();
				current_trail = inktrails.end();
				current_trail--;
				last_flushed_point = Geometry::Vector2<double>(e.x, e.y);
				current_trail->append(last_flushed_point);
			} else if (hypot(last_flushed_point.x - e.x, last_flushed_point.y - e.y) >= MIN_DRAG_DISTANCE) {
				last_flushed_point = Geometry::Vector2<double>(e.x, e.y);
				current_trail->append(last_flushed_point);
			}
		} else {
			is_drawing_trail = false;
		}
	}

	PlayableLevel::PlayableLevel(DeserializedLevelInformation &deserialized, Game &game)
			: game(game), blocks(deserialized.blocks), pockets(deserialized.pockets), balls(deserialized.balls) {
	}

}