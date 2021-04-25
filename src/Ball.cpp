
#include "Ball.h"

namespace Where1::InkBall {
	Ball::Ball(SDL_Texture &texture, Geometry::Vector2<double> position, Geometry::Vector2<double> velocity, Color ball_color)
			: texture(texture), position(position), velocity(velocity), color(ball_color) {

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
				.x = (int) (position.x - RADIUS),
				.y = (int) (position.y - RADIUS),
				.w = 2 * RADIUS,
				.h = 2 * RADIUS
		};
		SDL_RenderCopy(renderer, &texture, nullptr, &rect);
	}

	void Ball::reflect(Geometry::Vector2<double> reflection_vector) {
		Geometry::Vector2<double> normal_vector = reflection_vector.get_normal_vector().get_normalized();

		Geometry::Vector2<double> subtrahend = 2 * velocity.dot(normal_vector) * normal_vector;
		velocity = velocity - subtrahend;
	}

	bool Ball::collides_with(Geometry::Line<double> &line, int padding) {
		Geometry::Vector2<double> new_base = position - line.p2;
		Geometry::Vector2<double> new_p1 = line.p1 - line.p2;
		double k = new_base.dot(new_p1) / new_p1.magnitude_squared();

		// Ensure the point is on the line segment
		if (k < 0) {
			k = 0;
		} else if (k > 1) {
			k = 1;
		}

		Geometry::Vector2<double> scaled_p2 = (1 - k) * line.p2; // Because it doesn't like multiplying temporaries
		Geometry::Vector2<double> closest_point = k * line.p1 + scaled_p2;

		Geometry::Vector2<double> tmp(position.x, position.y);

		return closest_point.distance(tmp) <= RADIUS + padding;
	}

	bool Ball::collides_with(BoxCollidable<double> &box) {
		for (auto &line : box.get_bounding_lines()) {
			if (collides_with(line)) {
				return true;
			}
		}
		return false;
	}

	bool Ball::reflect_if_collides_with(BoxCollidable<double> &box) {
		// If it's outside the block and this is true it won't collide
		// If it's inside and this is true then it's leaving and we best not get in its way
		if (!is_travelling_towards(box)) {
			return false;
		}

		for (auto &line : box.get_bounding_lines()) {
			if (collides_with(line)) {
				reflect(line.p2 - line.p1);
				return true;
			}
		}

		return false;
	}

	bool Ball::is_travelling_towards(BoxCollidable<double> &box) {
		Geometry::Vector2<double> displacement = box.get_centre() - position;
		double correlation_coefficient = displacement.dot(velocity) / (displacement.magnitude() * velocity.magnitude());

		return correlation_coefficient > 0;
	}

	bool Ball::collides_with(InkTrail &inktrail) {
		for (auto &line : inktrail.get_bounding_lines()) {
			if (collides_with(line, InkTrail::PADDING)) {
				return true;
			}
		}

		return false;
	}

	bool Ball::reflect_if_collides_with(InkTrail &inktrail) {
		for (auto &line : inktrail.get_bounding_lines()) {
			if (collides_with(line)) {
				reflect(line);
				return true;
			}
		}

		return false;
	}

	void Ball::reflect(Geometry::Line<double> line) {
		reflect(line.p2 - line.p1);
	}
}