#include "Chip8VM/Chip8VM.h"
#include "Chip8VM/Util/Logger.h"

#include <SDL.h>

namespace C8VM
{
	Chip8VM::Chip8VM()
	{
		C8VM_LOG_INFO("C8VM Initializing...");
		std::unordered_map<char, C8VM::KeyCode> keymap;
		keymap[SDLK_1] = C8VM::KeyCode::N1;
		keymap[SDLK_2] = C8VM::KeyCode::N2;
		keymap[SDLK_3] = C8VM::KeyCode::N3;
		keymap[SDLK_c] = C8VM::KeyCode::KC;
		keymap[SDLK_4] = C8VM::KeyCode::N4;
		keymap[SDLK_5] = C8VM::KeyCode::N5;
		keymap[SDLK_6] = C8VM::KeyCode::N6;
		keymap[SDLK_d] = C8VM::KeyCode::KD;
		keymap[SDLK_7] = C8VM::KeyCode::N7;
		keymap[SDLK_8] = C8VM::KeyCode::N8;
		keymap[SDLK_9] = C8VM::KeyCode::N9;
		keymap[SDLK_e] = C8VM::KeyCode::KE;
		keymap[SDLK_a] = C8VM::KeyCode::KA;
		keymap[SDLK_0] = C8VM::KeyCode::N0;
		keymap[SDLK_b] = C8VM::KeyCode::KB;
		keymap[SDLK_f] = C8VM::KeyCode::KF;
		m_Keyboard.Remap(keymap);
		C8VM_LOG_INFO("C8VM Initialized!");
	}

	Chip8VM::~Chip8VM()
	{
		C8VM_LOG_INFO("C8VM Destroying...");
		C8VM_LOG_INFO("C8VM Destroyed!");
	}
}
