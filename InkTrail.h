
#ifndef INKBALL_INKTRAIL_H
#define INKBALL_INKTRAIL_H

#include "Vector2.h"
#include "Renderable.h"
#include "Updatable.h"
#include "Drawing.h"

#include <vector>

namespace Where1::InkBall {
	class InkTrail : public Renderable {
	public:
		InkTrail() = default;

		void draw(SDL_Renderer *renderer) override;

		void append(Geometry::Vector2<double> point);

		std::vector<Geometry::Line<double>> get_lines();
		static const int PADDING = 3;
	private:
		std::vector<Geometry::Vector2<double>> points;
		//static const int THICKNESS = 3;
	};
}

#endif //INKBALL_INKTRAIL_H
