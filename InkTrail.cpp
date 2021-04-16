
#include "InkTrail.h"

namespace Where1::InkBall {
	void InkTrail::draw(SDL_Renderer *renderer) {
		for(auto it = points.begin() + 1; it != points.end(); it++){
			SDL_Utilities::DrawLine(renderer, *(it - 1), *it, THICKNESS);
		}
	}

	void InkTrail::append(Geometry::Vector2<double> point) {
		points.push_back(point);
	}
}
