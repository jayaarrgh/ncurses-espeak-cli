#ifndef TTS_H
#define TTS_H

#include <iostream>
#include <cstring>
#include <espeak-ng/speak_lib.h>


class TextToSpeech {
private:
	/* static constexpr char voicename[] = {"English"};	 // Set voice by its name *1/ */
	espeak_AUDIO_OUTPUT m_output = AUDIO_OUTPUT_SYNCH_PLAYBACK;
	/* espeak_AUDIO_OUTPUT m_output = AUDIO_OUTPUT_SYNCHRONOUS; */
	char* m_path = NULL; // user default espeak-ng path
	void* m_user_data;
	unsigned int* m_identifier;
	int m_buflength = 500, m_options = 0;
	unsigned int m_position = 0, m_end_position = 0, m_flags = espeakCHARS_AUTO;
	espeak_POSITION_TYPE m_position_type = espeak_POSITION_TYPE::POS_SENTENCE;
public:
	TextToSpeech(){
	}
	
	~TextToSpeech() {
		espeak_Terminate();
		
	}
	
	void Initalize(){
		espeak_Initialize(m_output, m_buflength, m_path, m_options);
		char voicename[] = {"English"};	 // Set voice by its name
		espeak_SetVoiceByName(voicename);
	}

	void Initalize(std::string voicename){
		// convert string name input to char arr
		espeak_Initialize(m_output, m_buflength, m_path, m_options);
		int s_len = voicename.length();
		char voicename_char_array[s_len + 1];
		strcpy(voicename_char_array, voicename.c_str());	
		espeak_SetVoiceByName(voicename_char_array);
	}

	void Speak(const std::string& text) const {
		espeak_Synth(&text[0], m_buflength, m_position,
			m_position_type, m_end_position, m_flags, 
			NULL, m_user_data); 
			/* m_identifier, m_user_data); */
	}
};

#endif
