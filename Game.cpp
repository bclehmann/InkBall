
#include <iostream>
#include "Game.h"
#include "Drawing.h"
#include "Ball.h"

namespace Where1::InkBall {
	void Game::play() {
		unsigned long long now = SDL_GetPerformanceCounter();
		unsigned long long last = now;

		while (!should_quit) {
			last = now;
			now = SDL_GetPerformanceCounter();

			double delta_t = (now - last) / (double)SDL_GetPerformanceFrequency();

			SDL_Event event;
			while (!should_quit && SDL_PollEvent(&event)) {
				handle_event(event);
			}

			current_level.update(delta_t);
			current_level.draw(renderer.get());

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

		std::vector<Ball> balls = {Ball(*textures["blue_ball"], Geometry::Vector2<double>{0, 0}, Geometry::Vector2<double>{10, 5})};
		std::vector<Block> blocks = {Block(*textures["block"], Geometry::Vector2<int>{200, 200})};

		current_level = Level(balls, blocks);
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

			if (!textures[common_name].get()) {
				throw SDL_Utilities::SDLError("Could not load texture:");
			}
		}
	}
}