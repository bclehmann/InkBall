
#ifndef INKBALL_GAME_H
#define INKBALL_GAME_H

#include "SDLWindowDeleter.h"
#include "SDLError.h"
#include "SDLRendererDeleter.h"
#include "SDLTextureDeleter.h"
#include "Ball.h"
#include "PlayableLevel.h"
#include "InkTrail.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <unordered_map>
#include <vector>
#include <list>

class Level;

namespace Where1::InkBall {
	class Game {
	public:
		Game();

		~Game();

		void play();

		void quit();

		void lose();

		SDL_Texture &get_texture(std::string name);

		static const unsigned int TOP_BAR_HEIGHT = 30;
		static const unsigned int HEIGHT = 608 + TOP_BAR_HEIGHT;
		static const unsigned int WIDTH = 480;

	private:
		void handle_event(SDL_Event &event);

		void initialize_textures();

		bool should_quit = false;
		std::unique_ptr<SDL_Window, SDL_Utilities::SDLWindowDeleter> window;
		std::unique_ptr<SDL_Renderer, SDL_Utilities::SDLRendererDeleter> renderer;

		std::unordered_map<std::string, std::unique_ptr<SDL_Texture, SDL_Utilities::SDLTextureDeleter>> textures;
		std::string asset_path_prefix = "./assets/";
		std::string level_path_prefix = "./levels/";
		std::vector<std::pair<std::string, std::string>> texture_names{
			{"block", "block.png"},
			{"sparkle", "sparkle.png"},
			{"blue_ball", "blue_ball.png"},
			{"grey_ball", "grey_ball.png"},
			{"orange_ball", "orange_ball.png"},
			{"pink_ball", "pink_ball.png"},
			{"grey_pocket", "grey_pocket.png"},
			{"blue_pocket", "blue_pocket.png"},
			{"pink_pocket", "pink_pocket.png"},
			{"orange_pocket", "orange_pocket.png"},
		};

		std::unique_ptr<Level> current_level;
	};
}

#endif //INKBALL_GAME_H
