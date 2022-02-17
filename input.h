#ifndef INPUT_H
#define INPUT_H

#include "screen.h"

inline void handleCommand(const std::string& input, const Screen& screen) {
	std::string outText;
	if (input == "look") {
		outText = "You see nothing important.";
	}
	if (input == "move") {
		outText = "You move through the world.";
	}
	screen.Output(outText);
}

inline bool handleQuit(const std::string& input, const Screen& screen) {
	if (input == "q" || input == "quit" || input == "exit") {
		screen.Output("Good bye!");
		screen.Output("We patiently await your return.");
		return true;
	}
	return false;
}

#endif
