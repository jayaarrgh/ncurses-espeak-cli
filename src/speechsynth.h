#ifndef TTS_H
#define TTS_H

#include <string>

#include <espeak-ng/speak_lib.h>
/* #include <espeak/speak_lib.h> */


class TextToSpeech {
private:
	void* m_user_data;
	unsigned int* m_identifier;
	unsigned int m_position = 0, m_end_position = 0, m_flags = espeakCHARS_AUTO;
	int m_buflength = 500, m_options = 0;
	char* m_path = NULL; // user default espeak-ng path
	espeak_POSITION_TYPE m_position_type = espeak_POSITION_TYPE::POS_SENTENCE;
	espeak_AUDIO_OUTPUT m_output = AUDIO_OUTPUT_SYNCH_PLAYBACK;
	std::string m_voicename;
public:
	TextToSpeech();
	TextToSpeech(const std::string&);
	~TextToSpeech();
	void Initialize();
	void Speak(const std::string&) const;
};

#endif
