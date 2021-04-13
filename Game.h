
#ifndef INKBALL_GAME_H
#define INKBALL_GAME_H

#include "SDLWindowDeleter.h"
#include "SDLError.h"
#include "SDLRendererDeleter.h"
#include "SDLTextureDeleter.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <unordered_map>
#include <vector>

namespace Where1::InkBall {
	class Game {
	public:
		Game();

		~Game();

		void play();

		void quit();

	private:
		void handle_event(SDL_Event &event);

		void initialize_textures();

		bool should_quit = false;
		std::unique_ptr<SDL_Window, SDL_Utilities::SDLWindowDeleter> window;
		std::unique_ptr<SDL_Renderer, SDL_Utilities::SDLRendererDeleter> renderer;

		std::unordered_map<std::string, std::unique_ptr<SDL_Texture, SDL_Utilities::SDLTextureDeleter>> textures;
		std::string path_prefix = "./assets/";
		std::vector<std::pair<std::string, std::string>> texture_names{{"block", "block.png"}};
	};
}

#endif //INKBALL_GAME_H
