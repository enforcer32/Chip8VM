#pragma once

#include <cstdint>

/*
	Chip8 Memory Specifications
	Max Memory Size: 4096 Bytes
	Address 0x00-0x1FF: Reserved Reserved for Chip8 Internal
	Address 0x200-0xFFF: Reserved For Program Data
*/
#define C8VM_MAX_MEMORY_SIZE 0x1000
#define C8VM_INTERNAL_MEMORY_START 0x000
#define C8VM_INTERNAL_MEMORY_END 0x1FF
#define C8VM_PROGRAM_MEMORY_START 0x200
#define C8VM_PROGRAM_MEMORY_END 0xFFF

namespace C8VM
{
	class Memory
	{
	public:
		Memory();
		~Memory();

		uint8_t ReadUInt8(uint16_t offset);
		void WriteUInt8(uint16_t offset, uint8_t value);
		uint16_t ReadUInt16(uint16_t offset);
		void WriteUInt16(uint16_t offset, uint16_t value);

		inline uint8_t* GetMemory() { return m_Memory; }
		inline uint16_t GetMemorySize() { return C8VM_MAX_MEMORY_SIZE; }

	private:
		uint8_t m_Memory[C8VM_MAX_MEMORY_SIZE];
	};
}
