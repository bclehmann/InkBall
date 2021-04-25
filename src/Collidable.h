
#ifndef INKBALL_COLLIDABLE_H
#define INKBALL_COLLIDABLE_H

#include "Line.h"

#include <vector>

namespace Where1::InkBall {
	template<typename T>
	class Collidable {
	public:
		virtual std::vector<Geometry::Line<T>> get_bounding_lines() = 0;
	};
}


#endif //INKBALL_COLLIDABLE_H
