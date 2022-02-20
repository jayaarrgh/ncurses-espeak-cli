#include "speechsynth.h"


TextToSpeech::TextToSpeech(){
	this->m_voicename = "English";
}

TextToSpeech::TextToSpeech(const std::string& name){
	this->m_voicename = name;
}
	
TextToSpeech::~TextToSpeech() {
	espeak_Terminate();
}

void TextToSpeech::Initialize(){
	espeak_Initialize(m_output, m_buflength, m_path, m_options);
	espeak_SetVoiceByName(this->m_voicename.c_str());
}

void TextToSpeech::Speak(const std::string& text) const {
	espeak_Synth(&text[0], m_buflength, m_position,
		m_position_type, m_end_position, m_flags, 
		NULL, m_user_data); 
		/* m_identifier, m_user_data); */
}
