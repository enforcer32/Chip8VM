#include "Chip8VM/Register.h"
#include "Chip8VM/Util/Logger.h"

#include <cstring>

namespace C8VM
{
	Register::Register()
	{
		C8VM_LOG_INFO("C8VM->Register Initializing...");
		std::memset(this, 0, sizeof(Register));
		C8VM_LOG_INFO("C8VM->Register Initialized!");
	}

	Register::~Register()
	{
		C8VM_LOG_INFO("C8VM->Register Destroying...");
		C8VM_LOG_INFO("C8VM->Register Destroyed!");
	}
}
