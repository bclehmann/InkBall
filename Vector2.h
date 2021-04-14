
#ifndef INKBALL_VECTOR2_H
#define INKBALL_VECTOR2_H

namespace Where1::Geometry {
	template<typename T>
	class Vector2 {
	public:
		Vector2(T x, T y)
		: x(x), y(y)
		{

		}
		T x;
		T y;
	};
}

#endif //INKBALL_VECTOR2_H
