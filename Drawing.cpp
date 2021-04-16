
#include "Drawing.h"

namespace Where1::SDL_Utilities {
	int CircleError(int x, int y, int r) {
		return r * r - x * x - y * y;
	}

	void DrawCircle(SDL_Renderer *renderer, const int centre_x, const int centre_y, const int r) {
		const int r_squared = r * r;
		int y = r;
		int x = -1;

		do {
			x++;
			while (y * y + x * x >= r_squared) {
				y--;
			}


			// Above we calculate one point in one octant of the circle, now we exploit its symmetry
			SDL_Rect rects[]{
					{
							.x = centre_x - x,
							.y = centre_y - y,
							.w = 2 * x,
							.h = 2 * y
					},
					{
							.x = centre_x - y,
							.y = centre_y - x,
							.w = 2 * y,
							.h = 2 * x
					}
			};

			SDL_RenderFillRects(renderer, rects, 2);
		} while (y >= x);
	}

	void DrawLine(SDL_Renderer *renderer, Geometry::Line<double> line, int thickness) {
		DrawLine(renderer, line.p1, line.p2, thickness);
	}

	void DrawLine(SDL_Renderer *renderer, Geometry::Vector2<double> p1, Geometry::Vector2<double> p2, int thickness) {
		int medium = thickness / 2;

		Geometry::Vector2<double> displacement = (p2 - p1);
		Geometry::Vector2<double> normal_vector = displacement.get_normal_vector().get_normalized();

		for(int i = -medium; i <= medium; i++){
			Geometry::Vector2<double> pt1 = p1 + (double)i * normal_vector;
			Geometry::Vector2<double> pt2 = p2 + (double)i * normal_vector;

			SDL_RenderDrawLine(renderer, pt1.x, pt1.y, pt2.x, pt2.y);
		}

		return;;

		double angle = atan2(displacement.y, displacement.x);
		double angle_mod_90 = remainder(angle, M_PI / 2);

		for(int i = -medium; i <= medium; i++){
			if(angle_mod_90 >= 0 && angle_mod_90 <= M_PI / 4){
				SDL_RenderDrawLine(renderer, p1.x + i, p1.y, p2.x + i, p2.y);
			}else if(angle_mod_90 >= M_PI / 4 && angle_mod_90 <= M_PI / 2){
				SDL_RenderDrawLine(renderer, p1.x, p1.y + i, p2.x, p2.y + i);
			}
		}
	}

	void DrawLines(SDL_Renderer *renderer, std::vector<Geometry::Vector2<double>> points) {
		SDL_Point *point_array = new SDL_Point[points.size()];

		auto *x = malloc(500);
		if(x == nullptr){
			throw x;
		}

		for(int i = 0; i < points.size(); i++){
			point_array[i].x = (int)points[i].x;
			point_array[i].y = (int)points[i].y;
		}

		SDL_RenderDrawLines(renderer, point_array, points.size());
		delete[] point_array;
	}
}
