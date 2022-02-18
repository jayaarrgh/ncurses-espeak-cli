#ifndef TTS_H
#define TTS_H

#include <string>

#include <espeak-ng/speak_lib.h>


class TextToSpeech {
private:
	std::string voicename;
	/* = {"English"};	 // Set voice by its name *2/ *1/ */
	espeak_AUDIO_OUTPUT m_output = AUDIO_OUTPUT_SYNCH_PLAYBACK;
	char* m_path = NULL; // user default espeak-ng path
	void* m_user_data;
	unsigned int* m_identifier;
	int m_buflength = 500, m_options = 0;
	unsigned int m_position = 0, m_end_position = 0, m_flags = espeakCHARS_AUTO;
	espeak_POSITION_TYPE m_position_type = espeak_POSITION_TYPE::POS_SENTENCE;
public:
	TextToSpeech();
	TextToSpeech(const std::string&);
	~TextToSpeech();
	void Initialize();
	void Speak(const std::string&) const;
};

#endif
