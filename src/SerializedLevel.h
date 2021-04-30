
#ifndef INKBALL_SERIALIZEDLEVEL_H
#define INKBALL_SERIALIZEDLEVEL_H

#include "PlayableLevel.h"
#include "LevelSerialization.h"

namespace Where1::InkBall {
	class PlayableLevel;

	class SerializedLevel {
	public:
		explicit SerializedLevel(PlayableLevel *level_to_serialize);

		~SerializedLevel();

		void write(std::string path);

		static unsigned int required_size(PlayableLevel &level_to_serialize);

	private:
		void serialize();

		// So we don't accidentally use free on a buffer allocated with new or similar
		void free_buffer();

		void alloc_buffer(unsigned int size);

		PlayableLevel *level_to_serialize;
		unsigned char *buffer = nullptr;
	};
}


#endif //INKBALL_SERIALIZEDLEVEL_H
