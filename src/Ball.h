
#ifndef INKBALL_BALL_H
#define INKBALL_BALL_H

#include "Renderable.h"
#include "Vector2.h"
#include "Updatable.h"
#include "Line.h"
#include "Block.h"
#include "InkTrail.h"

#include <SDL2/SDL.h>

#include <string>
#include <vector>

namespace Where1::InkBall {
	class Ball : public Renderable, public Updatable {
	public:
		Ball(SDL_Texture &texture, Geometry::Vector2<double> position,
			 Geometry::Vector2<double> velocity);

		Geometry::Vector2<double> get_position() const;

		Geometry::Vector2<double> get_velocity() const;

		void update(double timestep) override;

		void draw(SDL_Renderer *renderer) override;

		void reflect(Geometry::Vector2<double> reflection_vector);
		void reflect(Geometry::Line<double> line);

		bool collides_with(Geometry::Line<double> &line, int padding = 0);
		bool collides_with(BoxCollidable<double> &box);
		bool collides_with(InkTrail &inktrail);

		bool is_travelling_towards(BoxCollidable<double> &box);

		bool reflect_if_collides_with(BoxCollidable<double> &box);
		bool reflect_if_collides_with(InkTrail &inktrail);


	private:
		SDL_Texture &texture;
		Geometry::Vector2<double> position;
		Geometry::Vector2<double> velocity;

		static const int RADIUS = 16;
	};
}


#endif //INKBALL_BALL_H
