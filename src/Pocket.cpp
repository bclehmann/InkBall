
#include "Pocket.h"

namespace Where1::InkBall {
	Pocket::Pocket(SDL_Texture &texture, Geometry::Vector2<double> position, Color color)
			: texture(texture), position(position), color(color) {

	}

	void Pocket::draw(SDL_Renderer *renderer) {
		SDL_Rect rect{
				.x = (int) position.x,
				.y = (int) position.y,
				.w = WIDTH,
				.h = HEIGHT
		};
		SDL_RenderCopy(renderer, &texture, nullptr, &rect);
	}

	Geometry::Vector2<double> Pocket::get_position() {
		return position;
	}

	double Pocket::get_padding() {
		return PADDING;
	}

	double Pocket::get_width() {
		return WIDTH;
	}

	double Pocket::get_height() {
		return HEIGHT;
	}
}
