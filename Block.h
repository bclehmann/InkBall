
#ifndef INKBALL_BLOCK_H
#define INKBALL_BLOCK_H

#include "Vector2.h"
#include "Renderable.h"

#include <SDL2/SDL.h>


namespace Where1::InkBall {
	class Block : public Renderable {
	public:
		Block(SDL_Texture &texture, Geometry::Vector2<int> position);

		Geometry::Vector2<int> get_position() const;

		void draw(SDL_Renderer *renderer) override;

		static const int width = 32;
	private:
		SDL_Texture &texture;
		Geometry::Vector2<int> position;

	};
}

#endif //INKBALL_BLOCK_H
