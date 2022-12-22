cmake_minimum_required(VERSION 3.24)

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
add_definitions(-DLIZKIT_OPENGL)
  
add_subdirectory(Game39541)
add_subdirectory(Lizkit)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)

set(VS_STARTUP_PROJECT Game39541)

file(COPY Game39541/Assets DESTINATION ${PROJECT_BINARY_DIR}/Game39541)
file(COPY Game39541/Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Game39541/Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)