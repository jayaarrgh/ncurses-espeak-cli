#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include "speachsynth.h"


class Screen {
	private:
		TextToSpeach m_tts;
		WINDOW * inWin;
		WINDOW * outWin;
		void setupInputWindow();
		void setupOutputWindow();
	public:
		Screen();
		~Screen();
		void IntroScreen();
		std::string GetUserInput();
		void Output(const std::string&) const;
};

#endif
