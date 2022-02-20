#include "screen.h"

Screen::Screen() {
	// create a single instace of tts for now
	// having difficulty with segfaults
	// prob not initializing, terminating and freeing resources properly
	/* this->m_tts = TextToSpeech{"f5"}; */
	this->m_tts = TextToSpeech{};
	// initializing tts in a second step for now
	// i don't know why but I can initalize in the constructor
	this->m_tts.Initialize();
	this->setupInputWindow();
	this->setupOutputWindow();
}

Screen::~Screen() {}

void Screen::setupInputWindow() {
	// setup input window
	int h = 3, w = COLS;
	this->inWin = newwin(h, w, LINES - 3, 0);
}

void Screen::setupOutputWindow() {
	// setup output window
	int oHeight = LINES - 3;
	int oWidth = COLS;
	this->outWin = newwin(oHeight, oWidth, 0, 0);
	// allow this window to "scroll"
	// 	if we want scroll back we need
	// 		handle KEY_UP/DOWN
	// 		and probably another lib (Pads)
	scrollok(outWin, TRUE);
	// print some empty lines to get the output at the bottom of the win
	// hacky, but I don't want to manage an index right now
	/* int outputIndex = LINES - 4; */
	for (int i = 0; i < LINES; i++) {
		wprintw(outWin, "\n", 0, 0);
	}
}

void Screen::IntroScreen() {
	int row, col;
	getmaxyx(stdscr, row, col); /* get the number of rows and columns */

	// The "move"s below make the text about center adjusted
	move((LINES / 2) - 1, (COLS / 2) - 11);
	printw("Welcome to the world!");
	refresh();
	this->m_tts.Speak("Welcome to the world!");

	printw("\n");
	move(LINES / 2, (COLS / 2) - 25);
	printw("Use the commands 'move' and 'look' to move and look");
	refresh();
	this->m_tts.Speak(
	    "Use the commands 'move' and 'look' to move and look");

	printw("\n");
	move((LINES / 2) + 2, (COLS / 2) - 17);
	printw("Press any character to continue...");
	refresh();
	this->m_tts.Speak("Press any character to continue...");

	// wait for input and clear and refresh
	getch();
	clear();
	refresh();
}

std::string Screen::GetInput() {
	wclear(this->inWin);	 // clears the text in the window
	box(this->inWin, 0, 0);	 // replace the box around the window
	wrefresh(this->inWin);	 // redraw inputWin

	char userInput[256];
	// move cursor to inside the inputWindow and getstr
	mvwgetstr(this->inWin, 1, 1, userInput);
	// compiler can do this for us
	/* return (std::string)userInput; */
	return userInput;
}

void Screen::Output(const std::string& text) const {
	wprintw(this->outWin, text.c_str());
	wrefresh(this->outWin);
	this->m_tts.Speak(text);
	wprintw(this->outWin, "\n");
	wrefresh(this->outWin);
}

