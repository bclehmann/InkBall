
#include "Block.h"

namespace Where1::InkBall {
	Block::Block(SDL_Texture &texture, Geometry::Vector2<double> position)
	: texture(texture)
	, position(position)
	{

	}

	Geometry::Vector2<double> Block::get_position() const {
		return position;
	}

	void Block::draw(SDL_Renderer *renderer) {
		SDL_Rect rect{
			.x = (int)position.x,
			.y = (int)position.y,
			.w = width,
			.h = width
		};
		SDL_RenderCopy(renderer, &texture, nullptr, &rect);
	}

	std::array<Geometry::Line<double>, 4> Block::get_bounding_lines() {
		Geometry::Vector2<double> top_left = get_position() + Geometry::Vector2<double>(-PADDING, -PADDING);
		Geometry::Vector2<double> top_right = get_position() + Geometry::Vector2<double>(Block::width + PADDING, -PADDING);
		Geometry::Vector2<double> bottom_left = get_position() + Geometry::Vector2<double>(-PADDING, Block::width + PADDING);
		Geometry::Vector2<double> bottom_right = get_position() + Geometry::Vector2<double>(Block::width + PADDING, Block::width + PADDING);

		Geometry::Line<double> l1(top_left, top_right);
		Geometry::Line<double> l2(top_left, bottom_left);
		Geometry::Line<double> l3(bottom_left, bottom_right);
		Geometry::Line<double> l4(top_right, bottom_right);
		return {l1, l2, l3, l4};
	}
}