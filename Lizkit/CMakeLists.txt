set(SOURCE_FILES
	LizkitApp.cpp
    )

set(HEADER_FILES
	Lizkit.h
	LizkitApp.h
	LizkitUtil.h
    )

add_library(Lizkit SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DLIZKIT_LIB)

target_precompile_headers(Lizkit PRIVATE pch.h)

include_directories(../glfw/include/)

target_link_libraries(Lizkit glfw)