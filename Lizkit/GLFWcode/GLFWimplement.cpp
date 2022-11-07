#include "pch.h"

#include "LizkitUtil.h"
#include "GLFWimplement.h"



namespace Lizkit {
	GLFWimplement::GLFWimplement(){
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			LIZKIT_LOG("Failed to initialize GLAD");
		}


		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


		
	}

	void GLFWimplement::Create(int width, int height, const std::string& windowName){
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);
	}

	void GLFWimplement::SwapBuffers(){
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}

	GLFWimplement::~GLFWimplement(){
		glfwTerminate();
	}


}