#include <ncurses.h>
#include "speechsynth.h"
#include "screen.h"

inline void handleCommand(const std::string& input, const Screen& screen) {
	std::string text;
	if (input == "look") {
		text = "You see nothing important.";
	}
	if (input == "move") {
		text = "You move through the world.";
	}
	screen.Output(text);
}

inline bool handleQuit(const std::string& input, const Screen& screen) {
	if (input == "q" || input == "quit" || input == "exit") {
		screen.Output("Good bye!");
		screen.Output("We patiently await your return.");
		return true;
	}
	return false;
}

