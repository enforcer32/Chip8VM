#pragma once

#include "Chip8VM/Util/Platform.h"
#include "Chip8VM/Util/Logger.h"

#if defined C8VM_DEBUG
	#ifdef C8VM_PLATFORM_WINDOWS
		#define C8VM_DEBUGBREAK() __debugbreak()	
	#else
		#error "Platform doesnt support debugbreak"
	#endif
	#define C8VM_ENABLE_ASSERTS
#else
	#define C8VM_DEBUGBREAK()
#endif

#ifdef C8VM_ENABLE_ASSERTS
	#define C8VM_ASSERT(x, msg) { if(!(x)) { C8VM_LOG_ERROR("Assertion Error: {}, File: {}, Line: {}", msg, __FILE__, __LINE__); C8VM_DEBUGBREAK(); } }
#else
	#define C8VM_ASSERT(...)
#endif
