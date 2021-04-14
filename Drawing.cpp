
#include "Drawing.h"

namespace Where1::SDL_Utilities{
	int CircleError(int x, int y, int r){
		return r * r - x * x - y * y;
	}

	void DrawCircle(SDL_Renderer *renderer, const int centre_x, const int centre_y, const int r) {
		const int r_squared = r * r;
		int y = r;
		int x = -1;

		do {
			x++;
			while(y * y + x * x >= r_squared){
				y--;
			}


			// Above we calculate one octant of the circle, now we exploit its symmetry
			SDL_RenderDrawLine(renderer, centre_x, centre_y, centre_x + x, centre_y + y);
			SDL_RenderDrawLine(renderer, centre_x, centre_y, centre_x + x, centre_y - y);
			SDL_RenderDrawLine(renderer, centre_x, centre_y, centre_x - x, centre_y + y);
			SDL_RenderDrawLine(renderer, centre_x, centre_y, centre_x - x, centre_y - y);

			SDL_RenderDrawLine(renderer, centre_x, centre_y, centre_x + y, centre_y + x);
			SDL_RenderDrawLine(renderer, centre_x, centre_y, centre_x + y, centre_y - x);
			SDL_RenderDrawLine(renderer, centre_x, centre_y, centre_x - y, centre_y + x);
			SDL_RenderDrawLine(renderer, centre_x, centre_y, centre_x - y, centre_y - x);

			SDL_Rect rect{
				.x = centre_x - x,
				.y = centre_y - y,
				.w = 2 * x,
				.h = 2 * y
			};

			SDL_RenderFillRect(renderer, &rect); // To fill in where it fringes, still need to convert to texture and draw texture
		}while(y >= x);
	}
}
