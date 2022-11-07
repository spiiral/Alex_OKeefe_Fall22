set(SOURCE_FILES
	LizkitApp.cpp
	LizkitWindow.cpp
	GLFWcode/GLFWimplement.cpp
	LizkitApp.cpp
    )

set(HEADER_FILES
	Lizkit.h
	LizkitApp.h
	LizkitUtil.h
	LizkitUtil.h
	WindowImplement.h
	GLFWcode/GLFWImplement.h
    )

add_library(Lizkit SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DLIZKIT_LIB)

target_precompile_headers(Lizkit PRIVATE pch.h)

include_directories(../glfw/include/)
include_directories(../Lizkit)
include_directories(../glad/include)

target_link_libraries(Lizkit glfw)