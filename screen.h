#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include "speechsynth.h"


class Screen {
	private:
		TextToSpeech m_tts;
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
