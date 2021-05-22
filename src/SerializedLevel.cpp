
#include "SerializedLevel.h"

#include <limits>
#include <fstream>

namespace Where1::InkBall {

	unsigned int SerializedLevel::required_size(PlayableLevel &level_to_serialize) {
		return sizeof(LevelHeader) + level_to_serialize.blocks.size() * sizeof(BlockInformation) +
			   level_to_serialize.pockets.size() * sizeof(PocketInformation) +
			   level_to_serialize.balls.size() * sizeof(BallInformation);
	}

	SerializedLevel::SerializedLevel(PlayableLevel *level_to_serialize)
			: level_to_serialize(level_to_serialize) {

	}

	void SerializedLevel::serialize() {
		free_buffer();

		unsigned int size = required_size(*level_to_serialize);
		alloc_buffer(size);

		if (level_to_serialize->blocks.size() > (int) std::numeric_limits<typeof(LevelHeader::num_blocks)>::max()) {
			throw std::overflow_error("Too many blocks to serialize");
		}

		if (level_to_serialize->pockets.size() > (int) std::numeric_limits<typeof(LevelHeader::num_pockets)>::max()) {
			throw std::overflow_error("Too many pockets to serialize");
		}

		if (level_to_serialize->balls.size() > (int) std::numeric_limits<typeof(LevelHeader::num_balls)>::max()) {
			throw std::overflow_error("Too many balls to serialize");
		}

		LevelHeader header;
		header.num_blocks = static_cast<typeof(LevelHeader::num_blocks)>(level_to_serialize->blocks.size());
		header.num_pockets = static_cast<uint8_t>(level_to_serialize->pockets.size());
		header.num_balls = static_cast<uint8_t>(level_to_serialize->balls.size());


		memcpy(buffer, &header, sizeof(LevelHeader));

		uint8_t *head = buffer + sizeof(LevelHeader);

		for (int i = 0; i < header.num_blocks; i++) {
			BlockInformation *block_head = reinterpret_cast<BlockInformation *>(head);

			Where1::Geometry::Vector2<double> pos = level_to_serialize->blocks[i].get_position();
			block_head->x = (float) pos.x;
			block_head->y = (float) pos.y;

			head += sizeof(BlockInformation);
		}

		for (int i = 0; i < header.num_pockets; i++) {
			PocketInformation *pocket_head = reinterpret_cast<PocketInformation *>(head);

			Where1::Geometry::Vector2<double> pos = level_to_serialize->pockets[i].get_position();
			pocket_head->x = (float) pos.x;
			pocket_head->y = (float) pos.y;
			pocket_head->color = level_to_serialize->pockets[i].color;

			head += sizeof(PocketInformation);
		}

		for (int i = 0; i < header.num_balls; i++) {
			BallInformation *ball_head = reinterpret_cast<BallInformation *>(head);

			Where1::Geometry::Vector2<double> pos = level_to_serialize->balls[i].get_position();
			Where1::Geometry::Vector2<double> vel = level_to_serialize->balls[i].get_velocity();
			ball_head->x = (float) pos.x;
			ball_head->y = (float) pos.y;
			ball_head->x_velocity = (float) vel.x;
			ball_head->y_velocity = (float) vel.y;
			ball_head->color = level_to_serialize->balls[i].color;

			head += sizeof(BallInformation);
		}
	}

	void SerializedLevel::free_buffer() {
		delete[] buffer;
		buffer = nullptr; // Prevents double freeing, delete[] on a nullptr is a noop
	}

	void SerializedLevel::alloc_buffer(unsigned int size) {
		buffer = new unsigned char[size];
	}

	SerializedLevel::~SerializedLevel() {
		free_buffer();
	}

	void SerializedLevel::write(std::string path) {
		if (level_to_serialize == nullptr) {
			throw std::invalid_argument("level_to_serialize is null.");
		}

		unsigned int expected_size = required_size(*level_to_serialize);
		serialize();

		std::fstream filestream = std::fstream(path.c_str(), std::ios_base::out);
		filestream.write(reinterpret_cast<const char *>(buffer), expected_size);
		filestream.flush();
	}

}
