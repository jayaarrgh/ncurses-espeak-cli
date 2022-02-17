#ifndef TTS_H
#define TTS_H

#include <string>

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
	
	void Initialize(){
		espeak_Initialize(m_output, m_buflength, m_path, m_options);
		char voicename[] = {"English"};	 // Set voice by its name
		espeak_SetVoiceByName(voicename);
	}

	void Initialize(const char * voicename){
		espeak_Initialize(m_output, m_buflength, m_path, m_options);
		espeak_SetVoiceByName(voicename);
	}

	void Speak(const std::string& text) const {
		espeak_Synth(&text[0], m_buflength, m_position,
			m_position_type, m_end_position, m_flags, 
			NULL, m_user_data); 
			/* m_identifier, m_user_data); */
	}
};

#endif
