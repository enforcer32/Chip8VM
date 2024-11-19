#include "Chip8VM/Stack.h"
#include "Chip8VM/Util/Logger.h"
#include "Chip8VM/Util/Assertion.h"

#include <cstring>

namespace C8VM
{
	Stack::Stack()
	{
		C8VM_LOG_INFO("C8VM->Stack Initializing...");
		std::memset(m_Stack, 0, sizeof(m_Stack));
		C8VM_LOG_INFO("C8VM->Stack Initialized!");
	}

	Stack::~Stack()
	{
		C8VM_LOG_INFO("C8VM->Stack Destroying...");
		C8VM_LOG_INFO("C8VM->Stack Destroyed!");
	}

	void Stack::Push16(Register& registers, uint16_t value)
	{
		C8VM_ASSERT((registers.SP + 1) < C8VM_STACK_SIZE, "C8VM::Stack->Push16 SP Out of Bounds");
		C8VM_LOG_DEBUG("C8VM->Stack Push16(SP={}, value={})", (registers.SP + 1), value);
		m_Stack[++registers.SP] = value;
	}

	uint16_t Stack::Pop16(Register& registers)
	{
		C8VM_ASSERT(registers.SP > 0, "C8VM::Stack->Pop16 SP Out of Bounds");
		uint16_t value = m_Stack[registers.SP];
		C8VM_LOG_DEBUG("C8VM->Stack Pop16(SP={}, value={})", registers.SP, value);
		registers.SP--;
		return value;
	}
}
