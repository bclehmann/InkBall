
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
}
