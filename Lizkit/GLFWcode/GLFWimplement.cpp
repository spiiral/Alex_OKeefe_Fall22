#include "pch.h"

#include "LizkitUtil.h"
#include "GLFWimplement.h"
#include "Event.h"



namespace Lizkit {
	GLFWimplement::GLFWimplement(){
	
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
	}

	void GLFWimplement::Create(int width, int height, const std::string& windowName){
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		glfwMakeContextCurrent(mWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
			LIZKIT_LOG("Failed to initialize GLAD");
		}
		glfwSetWindowUserPointer(mWindow, &mCallbacks);

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
				if (action == GLFW_PRESS || action == GLFW_REPEAT) {
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyPressedEvent event{ key };
					userPointer->keyPressedCallback(event);
				}
				else if (action == GLFW_RELEASE) {
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyReleasedEvent event{ key };
					userPointer->keyReleasedCallback(event);
				}
		    }
		);
	}

	void GLFWimplement::SwapBuffers(){
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}

	GLFWimplement::~GLFWimplement(){
		glfwTerminate();
	}

	void GLFWimplement::SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback) {
		mCallbacks.keyPressedCallback = keyPressedCallback;
	}

	void GLFWimplement::SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback) {
		mCallbacks.keyReleasedCallback = keyReleasedCallback;
	}

	

}