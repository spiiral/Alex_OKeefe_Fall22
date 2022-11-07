cmake_minimum_required(VERSION 3.20)

project(lizkit_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DLIZKIT_WINDOWS)
elseif(APPLE)
	add_definitions(-DLIZKIT_MAC)
else()
	add_definitions(-DLIZKIT_LINUX)
endif()

add_definitions(-DLIZKIT_DEBUG)

  
add_subdirectory(Game39541)
add_subdirectory(Lizkit)
add_subdirectory(glfw)

set(VS_STARTUP_PROJECT Game39541)