#include "Chip8VM/Memory.h"
#include "Chip8VM/Util/Logger.h"
#include "Chip8VM/Util/Assertion.h"

#include <cstring>

namespace C8VM
{
	Memory::Memory()
	{
		C8VM_LOG_INFO("C8VM->Memory Initializing...");
		std::memset(m_Memory, 0, sizeof(m_Memory));
		C8VM_LOG_INFO("C8VM->Memory Initialized!");
	}

	Memory::~Memory()
	{
		C8VM_LOG_INFO("C8VM->Memory Destroying...");
		C8VM_LOG_INFO("C8VM->Memory Destroyed!");
	}

	uint8_t Memory::ReadUInt8(uint16_t offset)
	{
		C8VM_ASSERT(offset < C8VM_MAX_MEMORY_SIZE, "C8VM::Memory->ReadUInt8 Offset Out of Bounds");
		C8VM_LOG_DEBUG("C8VM->Memory ReadUInt8(offset={})", offset);
		return m_Memory[offset];
	}

	void Memory::WriteUInt8(uint16_t offset, uint8_t value)
	{
		C8VM_ASSERT(offset < C8VM_MAX_MEMORY_SIZE, "C8VM::Memory->WriteUInt8 Offset Out of Bounds");
		C8VM_LOG_DEBUG("C8VM->Memory WriteUInt8(offset={}, value={})", offset, value);
		m_Memory[offset] = value;
	}

	uint16_t Memory::ReadUInt16(uint16_t offset)
	{
		C8VM_ASSERT(offset < C8VM_MAX_MEMORY_SIZE, "C8VM::Memory->ReadUInt16 Offset Out of Bounds");
		C8VM_LOG_DEBUG("C8VM->Memory ReadUInt16(offset={})", offset);
		return *((uint16_t*)(m_Memory + offset));
	}

	void Memory::WriteUInt16(uint16_t offset, uint16_t value)
	{
		C8VM_ASSERT(offset < C8VM_MAX_MEMORY_SIZE, "C8VM::Memory->WriteUInt16 Offset Out of Bounds");
		C8VM_LOG_DEBUG("C8VM->Memory WriteUInt16(offset={}, value={})", offset, value);
		*((uint16_t*)(m_Memory + offset)) = value;
	}
}
