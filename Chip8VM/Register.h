#pragma once

#include <cstdint>

/*
	Chip8 Register Specifications
	16 General Purpose 8-Bit Registers (Vx, x=0-F)
	16-Bit Register "I" for Storing Memory Address
	VF Register Is not a General-Purpose Registers, It's Is a Flag Register used by Certain Instructions
	2 Special Purpose 8-Bit Registers for Delay & Sound Timers. (When Non-Zero, Decrement at rate of 60Hz)
	16-Bit Program Counter(PC) Register for Storing Address of Current Instruction to Execute (Instruction is 2 Bytes in Size)
	8-Bit StackPointer (Points at Top of the Stack)
*/
#define C8VM_GPR_SIZE 16

namespace C8VM
{
	struct Register
	{
		uint8_t V[C8VM_GPR_SIZE];
		uint16_t I;
		uint8_t DT;
		uint8_t ST;
		uint16_t PC;
		uint8_t SP;

		Register();
		~Register();
	};
}
