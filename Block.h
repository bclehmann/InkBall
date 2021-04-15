
#ifndef INKBALL_BLOCK_H
#define INKBALL_BLOCK_H

#include "Vector2.h"
#include "Renderable.h"
#include "Line.h"

#include <SDL2/SDL.h>
#include <array>


namespace Where1::InkBall {
	class Block : public Renderable {
	public:
		Block(SDL_Texture &texture, Geometry::Vector2<double> position);

		Geometry::Vector2<double> get_position() const;

		void draw(SDL_Renderer *renderer) override;

		std::array<Geometry::Line<double>, 4> get_bounding_lines();

		static const int width = 32;
	private:
		SDL_Texture &texture;
		Geometry::Vector2<double> position;

		static const int padding = 3;

	};
}

#endif //INKBALL_BLOCK_H
