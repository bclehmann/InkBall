#include "Game.h"

// SDL will not be able to find main unless it has this signature even though the parameters are unused
int main(int argc, char *argv[]) {
	Where1::InkBall::Game  game;
	game.play();

	return 0;
}
