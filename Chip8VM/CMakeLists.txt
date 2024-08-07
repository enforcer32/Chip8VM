file(GLOB_RECURSE Chip8VMSources
	"${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
	
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/Platform.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/Assertion.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/Logger.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/Logger.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/FileIO.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/FileIO.cpp"
)

add_definitions(-DCHIP8VM_DEBUG)

add_executable(${CHIP8VM_TARGET_NAME} ${Chip8VMSources})
target_include_directories(${CHIP8VM_TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${CHIP8VM_TARGET_NAME} PRIVATE spdlog)
