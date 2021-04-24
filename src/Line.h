
#ifndef INKBALL_LINE_H
#define INKBALL_LINE_H

namespace Where1::Geometry {
	template<typename T>
	class Line {
	public:
		Line(Vector2 <T> p1, Vector2 <T> p2)
				: p1(p1), p2(p2) {}

		Vector2 <T> p1;
		Vector2 <T> p2;
	};
}

#endif //INKBALL_LINE_H
