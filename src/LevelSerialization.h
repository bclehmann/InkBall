
#ifndef INKBALL_LEVELSERIALIZATION_H
#define INKBALL_LEVELSERIALIZATION_H

#include <cstdint>
#include "Color.h"
#include "PlayableLevel.h"

namespace Where1::InkBall {

	// Binary Layout:
	// LevelHeader
	// BlockInformation[num_blocks]
	// PocketInformation[num_pockets]
	// BallInformation[num_balls]
	struct alignas(4) LevelHeader {
		const char magic_number[8] = {'I', 'N', 'K', 'L', 'E', 'V', 'E', 'L'}; // Can't use a string literal or it would be null terminated

		const uint16_t version_major = 1;
		const uint16_t version_minor = 1;

		uint16_t num_blocks;
		uint8_t num_pockets;
		uint8_t num_balls;
	};

	struct alignas(4) BlockInformation {
		float x;
		float y;
	};

	struct alignas(4) PocketInformation {
		float x;
		float y;
		Color color;
	};

	struct alignas(4) BallInformation {
		float x;
		float y;

		float x_velocity;
		float y_velocity;

		Color color;
	};

};

#endif //INKBALL_LEVELSERIALIZATION_H
