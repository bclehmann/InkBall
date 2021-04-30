
#include <iostream>
#include "Game.h"
#include "GameOverLevel.h"
#include "LevelDeserialization.h"
#include "SerializedLevel.h"

#include <SDL2/SDL_ttf.h>

namespace Where1::InkBall {
	void Game::play() {
		unsigned long long now = SDL_GetPerformanceCounter();
		unsigned long long last = now;

		while (!should_quit) {
			SDL_Event event;
			while (!should_quit && SDL_PollEvent(&event)) {
				handle_event(event);
				now = SDL_GetPerformanceCounter();
			}

			last = now;
			now = SDL_GetPerformanceCounter();
			double delta_t = (now - last) / (double) SDL_GetPerformanceFrequency();

			const double max_timestep = 1 / 60.0;

			while (delta_t > 1 / 60.0) {
				delta_t -= max_timestep;
				current_level->update(max_timestep);
			}

			if (delta_t > 0) {
				current_level->update(delta_t);
			}

			current_level->draw(renderer.get());

			SDL_RenderPresent(renderer.get());
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
			case SDL_MOUSEMOTION: {
				current_level->handle_mouse_move(event.motion);
				break;
			}
			default:
				//printf("%d\n", event.type);
				break;
		}
	}

	Game::Game() {
		window = std::unique_ptr<SDL_Window, SDL_Utilities::SDLWindowDeleter>(
				SDL_CreateWindow("InkBall", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
								 SDL_WINDOW_OPENGL));


		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();

		if (!window) {
			throw SDL_Utilities::SDLError("Could not create Game window:");
		}

		renderer = std::unique_ptr<SDL_Renderer, SDL_Utilities::SDLRendererDeleter>(
				SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED));

		if (!renderer) {
			throw SDL_Utilities::SDLError("Could not create Game renderer:");
		}

		initialize_textures();

		std::string level_path = level_path_prefix + std::string("Level 1.ikl");
		DeserializedLevelInformation deserialized = LevelDeserialization::read(level_path, *this);
		current_level = std::make_unique<PlayableLevel>(deserialized, *this);
	}

	Game::~Game() {
		TTF_Quit();
		SDL_Quit();
	}

	void Game::initialize_textures() {
		for (auto &texture_info : texture_names) {
			std::string &common_name = texture_info.first;
			std::string &filename = texture_info.second;

			std::string path = asset_path_prefix + filename;
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

			if (!textures[common_name].get()) {
				throw SDL_Utilities::SDLError("Could not load texture:");
			}
		}
	}

	void Game::lose() {
		current_level = std::make_unique<GameOverLevel>();
	}

	SDL_Texture &Game::get_texture(std::string name) {
		return *textures[name];
	}
}