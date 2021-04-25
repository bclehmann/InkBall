
#ifndef INKBALL_POCKET_H
#define INKBALL_POCKET_H

#include "Renderable.h"
#include "Vector2.h"
#include "Line.h"
#include "BoxCollidable.h"
#include "Color.h"

#include <array>

namespace Where1::InkBall {
	class Pocket : public Renderable, public BoxCollidable<double> {
	public:
		Pocket(SDL_Texture &texture, Geometry::Vector2<double> position, Color color);

		virtual Geometry::Vector2<double> get_position() override;

		virtual double get_padding() override;

		virtual double get_width() override;

		virtual double get_height() override;

		void draw(SDL_Renderer *renderer) override;

		const Color color;

		static const int SIZE = 32;
		static const int WIDTH = SIZE;
		static const int HEIGHT = SIZE;
	private:
		SDL_Texture &texture;
		Geometry::Vector2<double> position;
		static const int PADDING = 0;
	};
};


#endif //INKBALL_POCKET_H
