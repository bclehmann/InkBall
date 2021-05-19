
#ifndef INKBALL_LEVELDESERIALIZATION_H
#define INKBALL_LEVELDESERIALIZATION_H

#include "Block.h"
#include "Pocket.h"
#include "Ball.h"
#include "Game.h"

#include <vector>

namespace Where1::InkBall {
	class Game;

	struct DeserializedLevelInformation {
		std::vector<Block> blocks;
		std::vector<Pocket> pockets;
		std::vector<Ball> balls;
	};

	class LevelDeserialization {
	public:
		static DeserializedLevelInformation read(std::string path, Game &game);

	private:
		static DeserializedLevelInformation deserialize(unsigned char *buffer, Game &game, size_t bytes);
	};

}


#endif //INKBALL_LEVELDESERIALIZATION_H
