#include "Chip8VM/Util/Logger.h"

int main(int argc, char** argv)
{
	C8VM::Logger::Init();
	C8VM_LOG_INFO("Chip8VM");

	return 0;
}
