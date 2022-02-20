
#ifndef INKBALL_BLOCK_H
#define INKBALL_BLOCK_H

#include "Vector2.h"
#include "Renderable.h"
#include "Line.h"
#include "BoxCollidable.h"

#include <SDL.h>
#include <array>


namespace Where1::InkBall {
	class Block : public Renderable, public BoxCollidable<double> {
	public:
		Block(SDL_Texture &texture, Geometry::Vector2<double> position);

		Geometry::Vector2<double> get_position() override;

		double get_padding() override;

		double get_width() override;

		double get_height() override;

		void draw(SDL_Renderer *renderer) override;

		static const int SIZE = 16;
		static const int WIDTH = SIZE;
		static const int HEIGHT = SIZE;
	private:
		SDL_Texture &texture;
		Geometry::Vector2<double> position;

		static const int PADDING = 3;
	};
}

#endif //INKBALL_BLOCK_H
