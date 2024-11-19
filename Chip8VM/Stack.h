#pragma once

#include "Chip8VM/Register.h"

/*
	Chip8 Stack Specifications
	Stack: Array of 16, 16-Bit Values
	Stores Function Return Address
	Max 16 Recursion Calls
	Stack is Separate from Main Memory
*/
#define C8VM_STACK_SIZE 16

namespace C8VM
{
	class Stack
	{
	public:
		Stack();
		~Stack();

		void Push16(Register& registers, uint16_t value);
		uint16_t Pop16(Register& registers);

	private:
		uint16_t m_Stack[C8VM_STACK_SIZE];
	};
}
