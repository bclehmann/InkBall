
#include "Block.h"

namespace Where1::InkBall {
	Block::Block(SDL_Texture &texture, Geometry::Vector2<double> position)
	: texture(texture)
	, position(position)
	{

	}

	Geometry::Vector2<double> Block::get_position() {
		return position;
	}

	void Block::draw(SDL_Renderer *renderer) {
		SDL_Rect rect{
			.x = (int)position.x,
			.y = (int)position.y,
			.w = WIDTH,
			.h = WIDTH
		};
		SDL_RenderCopy(renderer, &texture, nullptr, &rect);
	}

	double Block::get_padding() {
		return PADDING;
	}

	double Block::get_width() {
		return WIDTH;
	}

	double Block::get_height() {
		return HEIGHT;
	}
}