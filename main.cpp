#include <iostream>
#include <memory>
#include "SDL2/SDL.h"
#include "SDLWindowDeleter.h"
#include "Game.h"



int main(int argc, char *argv[]) {
	Where1::InkBall::Game  game;
	game.play();

	return 0;
}
