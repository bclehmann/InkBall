
#include <iostream>
#include "Game.h"

namespace Where1::InkBall {
	void Game::play() {
		while (!should_quit) {
			SDL_Event event;
			while (!should_quit && SDL_PollEvent(&event)) {
				handle_event(event);
			}

			SDL_Renderer *render_ptr = renderer.get();


			SDL_SetRenderDrawColor(render_ptr, 200, 200, 200, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(renderer.get());

			SDL_SetRenderDrawColor(render_ptr, 255, 255, 255, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawLine(render_ptr, 320, 200, 300, 240);

			SDL_Rect rect;
			rect.x = 200;
			rect.y = 200;
			rect.w = 32;
			rect.h = 32;
			SDL_RenderCopy(render_ptr, textures["block"].get(), NULL, &rect);

			SDL_RenderPresent(render_ptr);
		}
	}

	void Game::quit() {
		should_quit = true;
	}

	void Game::handle_event(SDL_Event &event) {
		switch (event.type) {
			case SDL_QUIT:
				quit();
				break;
			default:
				//printf("%d\n", event.type);
				break;
		}
	}

	Game::Game() {
		window = std::unique_ptr<SDL_Window, SDL_Utilities::SDLWindowDeleter>(
				SDL_CreateWindow("InkBall", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 600,
								 SDL_WINDOW_OPENGL));


		SDL_Init(SDL_INIT_VIDEO);

		if (!window) {
			throw SDL_Utilities::SDLError("Could not create Game window:");
		}

		renderer = std::unique_ptr<SDL_Renderer, SDL_Utilities::SDLRendererDeleter>(
				SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED));

		if (!renderer) {
			throw SDL_Utilities::SDLError("Could not create Game renderer:");
		}

		initialize_textures();
	}

	Game::~Game() {
		SDL_Quit();
	}

	void Game::initialize_textures() {
		for (auto &texture_info : texture_names) {
			std::string &common_name = texture_info.first;
			std::string &filename = texture_info.second;

			std::string path = path_prefix + filename;
			SDL_Surface *surface = IMG_Load(path.c_str());

			if (surface == nullptr) {
				std::string message = "Could not load surface from ";
				message += path + ":";
				throw SDL_Utilities::SDLError(message.c_str());
			}

			textures[common_name] = std::unique_ptr<SDL_Texture, SDL_Utilities::SDLTextureDeleter>(
					SDL_CreateTextureFromSurface(renderer.get(), surface));

			if (surface != nullptr)
				SDL_FreeSurface(surface);

			if (textures[common_name].get() == nullptr) {
				throw SDL_Utilities::SDLError("Could not load texture:");
			}
		}
	}
}