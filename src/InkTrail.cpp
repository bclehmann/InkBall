
#include "InkTrail.h"

namespace Where1::InkBall {
	void InkTrail::draw(SDL_Renderer *renderer) {
		SDL_Utilities::DrawLines(renderer, points);

//		for(auto it = points.begin() + 1; it != points.end(); it++){
//			SDL_Utilities::DrawLine(renderer, *(it - 1), *it, THICKNESS);
//		}
	}

	void InkTrail::append(Geometry::Vector2<double> point) {
		points.push_back(point);
	}

	std::vector<Geometry::Line<double>> InkTrail::get_bounding_lines() {
		std::vector<Geometry::Line<double>> output;

		if(points.empty()){
			return output;
		}

		Geometry::Vector2<double> last = points.front();

		for(auto it = points.begin() + 1; it != points.end(); it++){
			output.emplace_back(last, *it);
			last = *it;
		}

		return output;
	}
}
