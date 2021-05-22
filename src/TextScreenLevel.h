
#ifndef INKBALL_TEXTSCREENLEVEL_H
#define INKBALL_TEXTSCREENLEVEL_H


#include <string>
#include "Level.h"
#include "Game.h"

namespace Where1::InkBall {
	class TextScreenLevel : public Level {
	public:
		explicit TextScreenLevel(std::string surtext);

		void draw(SDL_Renderer *renderer) override;

		void update(double timestep) override;

		virtual bool is_menu() override;

	private:
		std::string surtext;
	};
}


#endif //INKBALL_TEXTSCREENLEVEL_H
