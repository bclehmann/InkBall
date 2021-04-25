
#ifndef INKBALL_BOXCOLLIDABLE_H
#define INKBALL_BOXCOLLIDABLE_H

#include "Collidable.h"
#include "Line.h"
#include "Vector2.h"

#include <vector>

namespace Where1::InkBall {
	template<typename T>
	class BoxCollidable : Collidable<T> {
	public:
		std::vector<Geometry::Line<T>> get_bounding_lines() override {
			auto position = get_position();
			auto padding = get_padding();
			auto width = get_width();
			auto height = get_height();

			Geometry::Vector2<T> top_left = position + Geometry::Vector2<T>(-padding, -padding);
			Geometry::Vector2<T> top_right = position + Geometry::Vector2<T>(width + padding, -padding);
			Geometry::Vector2<T> bottom_left = position + Geometry::Vector2<T>(-padding, height + padding);
			Geometry::Vector2<T> bottom_right = position + Geometry::Vector2<T>(width + padding, height + padding);

			Geometry::Line<T> l1 = Geometry::Line<T>(top_left, top_right);
			Geometry::Line<T> l2(top_left, bottom_left);
			Geometry::Line<T> l3(bottom_left, bottom_right);
			Geometry::Line<T> l4(top_right, bottom_right);

			return {l1, l2, l3, l4};
		}

		Geometry::Vector2<T> get_centre() {
			return get_position() + Geometry::Vector2<double>(get_width() / (T)2, get_height() / (T)2);
		}

		virtual Geometry::Vector2<T> get_position() = 0;

		virtual T get_padding() = 0;

		virtual T get_width() = 0;

		virtual T get_height() = 0;

	private:

	};
}


#endif //INKBALL_BOXCOLLIDABLE_H
