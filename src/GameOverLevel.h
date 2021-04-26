
#ifndef INKBALL_GAMEOVERLEVEL_H
#define INKBALL_GAMEOVERLEVEL_H

#include "Level.h"

namespace Where1::InkBall {
	class GameOverLevel : public Level {
		void draw(SDL_Renderer *renderer) override;

		void update(double timestep) override;
	};
}

#endif //INKBALL_GAMEOVERLEVEL_H
