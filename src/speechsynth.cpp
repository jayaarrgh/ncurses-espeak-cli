#include "speechsynth.h"


TextToSpeech::TextToSpeech(){
	this->voicename = "English";
}

TextToSpeech::TextToSpeech(const std::string& name){
	this->voicename = std::move(name);
}
	
TextToSpeech::~TextToSpeech() {
	espeak_Terminate();
}

void TextToSpeech::Initialize(){
	espeak_Initialize(m_output, m_buflength, m_path, m_options);
	espeak_SetVoiceByName(this->voicename.c_str());
}

void TextToSpeech::Speak(const std::string& text) const {
	espeak_Synth(&text[0], m_buflength, m_position,
		m_position_type, m_end_position, m_flags, 
		NULL, m_user_data); 
		/* m_identifier, m_user_data); */
}
