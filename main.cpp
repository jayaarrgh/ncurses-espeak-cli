#include <iostream>

#include <ncurses.h>

#include "speechsynth.h"
#include "screen.h"
#include "input.h"


/* https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ */
/* https://www.youtube.com/watch?v=4TRUf75mJNU&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=12 */


int main() {

	initscr();

	Screen screen;
	screen.IntroScreen();
	
	// game loop
	bool exit = false;
	while (!exit) {
		// get input and refresh input window
		std::string input = screen.GetUserInput();	
		
		// handle user input (and effect the game world/display)
		handleCommand(input, screen);
		exit = handleQuit(input, screen);
	}

	endwin();
	return 0;
}
