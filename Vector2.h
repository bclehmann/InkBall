
#ifndef INKBALL_VECTOR2_H
#define INKBALL_VECTOR2_H

#include <cmath>

namespace Where1::Geometry {
	template<typename T>
	class Vector2 {
	public:
		Vector2(T x, T y)
				: x(x), y(y) {}

		T x;
		T y;

		Vector2<T> get_normal_vector(){
			return Vector2<T>(y, x);
		}

		T dot(Vector2<T> &other){
			return x * other.x + y * other.y;
		}

		T magnitude_squared(){
			return dot(*this);
		}

		T magnitude(){
			return std::sqrt(magnitude_squared());
		}

		Vector2<T> get_normalized(){
			T norm = magnitude();
			return Vector2<T>(x / norm, y / norm);
		}

		Vector2<T> operator+(Vector2<T> &other){
			return Vector2<T>(x + other.x, y + other.y);
		}

		Vector2<T> operator-(Vector2<T> &other){
			return Vector2<T>(x - other.x, y - other.y);
		}

		T distance(Vector2<T> &other){
			Vector2<T> tmp = (*this - other);
			return tmp.magnitude_squared();
		}

	};

	template<typename T>
	Vector2<T> operator*(Vector2<T> &v, T multiple){
		return Vector2<T>(v.x * multiple, v.y * multiple);
	}

	template<typename T>
	Vector2<T> operator*(T multiple, Vector2<T> &v){
		return Vector2<T>(v.x * multiple, v.y * multiple);
	}
}

#endif //INKBALL_VECTOR2_H
