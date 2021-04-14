
#include "Block.h"

namespace Where1::InkBall {
	Block::Block(SDL_Texture &texture, Geometry::Vector2<int> position)
	: texture(texture)
	, position(position)
	{

	}

	Geometry::Vector2<int> Block::get_position() const {
		return position;
	}

	void Block::draw(SDL_Renderer *renderer) {
		SDL_Rect rect{
			.x = position.x,
			.y = position.y,
			.w = width,
			.h = width
		};
		SDL_RenderCopy(renderer, &texture, nullptr, &rect);
	}
}