#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../WindowImplement.h"

namespace Lizkit{
	class GLFWimplement : public WindowImplement {
	public:
		GLFWimplement();

		void Create(int width, int height, const std::string& windowName) override;
		void SwapBuffers() override;

		~GLFWimplement();

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback) override;

		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback) override;

	private:
		GLFWwindow* mWindow{ nullptr };
		int c = GLFW_KEY_UP;
		struct Callbacks {
			std::function<void(const KeyPressedEvent&)> keyPressedCallback{ [](const KeyPressedEvent&) {} };
			std::function<void(const KeyReleasedEvent&)> keyReleasedCallback{ [](const KeyReleasedEvent&) {} };
		} mCallbacks;

	};

}