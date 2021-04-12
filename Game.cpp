
#include "Game.h"

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
		SDL_RenderCopy(render_ptr, block_texture.get(), NULL, &rect);

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
	window = std::unique_ptr<SDL_Window, SDLWindowDeleter>(
			SDL_CreateWindow("InkBall", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 600, SDL_WINDOW_OPENGL));


	SDL_Init(SDL_INIT_VIDEO);

	if (!window) {
		throw SDLError("Could not create Game window:");
	}

	renderer = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED));

	if(!renderer){
		throw SDLError("Could not create Game renderer:");
	}

	initialize_textures();
}

Game::~Game() {
	SDL_Quit();
}

void Game::initialize_textures() {
	SDL_Surface *block_surface = IMG_Load("./assets/block.png");

	if(block_surface == nullptr){
		throw SDLError("Could not load block surface:");
	}

	block_texture = std::unique_ptr<SDL_Texture, SDLTextureDeleter>(SDL_CreateTextureFromSurface(renderer.get(), block_surface));

	if(block_surface != nullptr)
		SDL_FreeSurface(block_surface);

	if(!block_texture){
		throw SDLError("Could not load block texture:");
	}
}
