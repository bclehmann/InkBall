
#include "Ball.h"

namespace Where1::InkBall {
	Ball::Ball(SDL_Texture &texture, Geometry::Vector2<double> position,
			   Geometry::Vector2<double> velocity)
			: texture(texture), position(position), velocity(velocity) {

	}

	Geometry::Vector2<double> Ball::get_velocity() const {
		return velocity;
	}

	Geometry::Vector2<double> Ball::get_position() const {
		return position;
	}

	void Ball::update(double timestep) {
		position.x += timestep * velocity.x;
		position.y += timestep * velocity.y;
	}

	void Ball::draw(SDL_Renderer *renderer) {
		SDL_Rect rect{
			.x = (int)(position.x - radius),
			.y = (int)(position.y - radius),
			.w = 2 * radius,
			.h = 2 * radius
		};
		SDL_RenderCopy(renderer, &texture, nullptr, &rect);
	}
}