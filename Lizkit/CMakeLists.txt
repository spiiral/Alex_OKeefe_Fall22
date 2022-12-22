set(SOURCE_FILES
	Event.cpp
	OpenGLCode/OpenGLPicture.cpp
	OpenGLCode/OpenGLShader.cpp
	OpenGLCode/OpenGLRenderer.cpp
	Picture.cpp
	Shader.cpp
	Renderer.cpp
	Unit.cpp
	LizkitApp.cpp
	LizkitWindow.cpp
	GLFWcode/GLFWimplement.cpp
	LizkitApp.cpp
    )

set(HEADER_FILES
	OpenGLCode/OpenGLPicture.h
	OpenGLCode/OpenGLShader.h
	OpenGLCode/OpenGLRenderer.h
	Event.h
	Keys.h
	Picture.h
	Shader.h
	Renderer.h
	PictureImplement.h
	ShaderImplement.h
	RendererImplement.h
	Unit.h
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
include_directories(../stbi)

target_link_libraries(Lizkit glfw glad stbi)