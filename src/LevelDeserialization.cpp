
#include <fstream>
#include "LevelDeserialization.h"
#include "LevelSerialization.h"

namespace Where1::InkBall {
	DeserializedLevelInformation LevelDeserialization::deserialize(unsigned char *buffer, Game &game, size_t bytes) {
		LevelHeader *header = reinterpret_cast<LevelHeader *>(buffer);

		if (bytes < sizeof(LevelHeader)) {
			throw std::out_of_range("Not enough space for LevelHeader");
		}

		if (header->version_major != 1 || header->version_minor != 1) {
			throw std::invalid_argument("Unrecognized file format version. Could not deserialize.");
		}

		size_t bytes_needed = sizeof(LevelHeader) + header->num_blocks * sizeof(BlockInformation) +
							  header->num_pockets * sizeof(PocketInformation) +
							  header->num_balls * sizeof(BallInformation);

		if(bytes_needed != bytes){
			throw std::out_of_range("File and required file size mismatch");
		}

		DeserializedLevelInformation return_value;

		uint8_t *head = buffer + sizeof(LevelHeader);
		for (int i = 0; i < header->num_blocks; i++) {
			BlockInformation *block_head = reinterpret_cast<BlockInformation *>(head);

			Geometry::Vector2<double> pos(block_head->x, block_head->y);
			return_value.blocks.emplace_back(game.get_texture("block"), pos);

			head += sizeof(BlockInformation);
		}

		for (int i = 0; i < header->num_pockets; i++) {
			PocketInformation *pocket_head = reinterpret_cast<PocketInformation *>(head);

			Geometry::Vector2<double> pos(pocket_head->x, pocket_head->y);
			Color pocket_color = pocket_head->color;

			std::string texture_name;

			switch (pocket_color) {
				case Color::Grey:
					texture_name = "grey_pocket";
					break;
				case Color::Blue:
					texture_name = "blue_pocket";
					break;
				case Color::Pink:
					texture_name = "pink_pocket";
					break;
				case Color::Orange:
					texture_name = "orange_pocket";
					break;
				default:
					throw std::invalid_argument("Invalid pocket color");
					break;
			}

			return_value.pockets.emplace_back(game.get_texture(texture_name), pos, pocket_color);

			head += sizeof(PocketInformation);
		}

		for (int i = 0; i < header->num_balls; i++) {
			BallInformation *ball_head = reinterpret_cast<BallInformation *>(head);

			Geometry::Vector2<double> pos(ball_head->x, ball_head->y);
			Geometry::Vector2<double> vel(ball_head->x_velocity, ball_head->y_velocity);
			Color ball_color = ball_head->color;

			std::string texture_name;

			switch (ball_color) {
				case Color::Grey:
					texture_name = "grey_ball";
					break;
				case Color::Blue:
					texture_name = "blue_ball";
					break;
				case Color::Pink:
					texture_name = "pink_ball";
					break;
				case Color::Orange:
					texture_name = "orange_ball";
					break;
				default:
					throw std::invalid_argument("Invalid ball color");
					break;
			}

			return_value.balls.emplace_back(game.get_texture(texture_name), pos, vel, ball_color);

			head += sizeof(BallInformation);
		}

		return return_value;
	}

	DeserializedLevelInformation LevelDeserialization::read(std::string path, Game &game) {
		const size_t MAX_SIZE = 10 * 1024;

		FILE *fp = fopen(path.c_str(), "r");
		fseek(fp, 0, SEEK_END);
		size_t file_size = ftell(fp);
		rewind(fp);

		char *local_buffer = new char[file_size];
		size_t read_chars = fread(local_buffer, 1, file_size, fp);

		if (read_chars != file_size) {
			throw std::length_error("read_chars differed from file size");
		}

		DeserializedLevelInformation result = deserialize(reinterpret_cast<unsigned char *>(local_buffer), game, file_size);

		return result;

	}
}
