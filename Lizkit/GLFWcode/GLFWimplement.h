#pragma once
#include "../pch.h"

//#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../WindowImplement.h"

namespace Lizkit{
	class GLFWimplement : public WindowImplement {
	public:
		GLFWimplement();

		void Create(int width, int height, const std::string& windowName) override;
		void SwapBuffers() override;

		~GLFWimplement();

	private:
		GLFWwindow* mWindow{ nullptr };

	};

}