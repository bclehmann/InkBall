
#include "Level.h"

namespace Where1::InkBall{
	void Level::draw(SDL_Renderer *renderer) {
		for(auto& curr : blocks){
			curr.draw(renderer);
		}

		for(auto& curr : balls){
			curr.draw(renderer);
		}
	}

	void Level::update(double timestep) {
		for(auto& curr : balls){
			curr.update(timestep);
		}
	}
}