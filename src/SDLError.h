
#ifndef INKBALL_SDLERROR_H
#define INKBALL_SDLERROR_H

#include <SDL.h>

#include <exception>
#include <string>
#include <cstring>

namespace Where1::SDL_Utilities {
	class SDLError : public std::exception {
	public:
		explicit SDLError(const char *error_message) {
			std::string tmp = error_message;
			tmp += ' ';
			tmp += SDL_GetError(); // If this was all on one line it would do pointer addition because C++

			message = new char[tmp.length() + 1];
			strncpy(message, tmp.c_str(), tmp.length() + 1);
			message[tmp.length()] = '\0'; // Safety first
		}

		SDLError()
				: SDLError("") {
		}

		char *message;

		const char *what() const noexcept override {
			return message;
		}
	};
}

#endif //INKBALL_SDLERROR_H
