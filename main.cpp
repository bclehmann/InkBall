#include <iostream>
#include <memory>
#include "SDL2/SDL.h"
#include "SDLWindowDeleter.h"
#include "Game.h"



int main(int argc, char *argv[]) {
	Game game;
	game.play();

	return 0;
}
