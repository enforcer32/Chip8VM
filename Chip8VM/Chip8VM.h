#pragma once

#include "Chip8VM/Memory.h"
#include "Chip8VM/Register.h"
#include "Chip8VM/Stack.h"
#include "Chip8VM/Keyboard.h"
#include "Chip8VM/Display.h"

namespace C8VM
{
	class Chip8VM
	{
	public:
		Chip8VM();
		~Chip8VM();

	private:
		Memory m_Memory;
		Register m_Registers;
		Stack m_Stack;
		Keyboard m_Keyboard;
	};
}
