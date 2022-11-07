#pragma once
#include "pch.h"

namespace Lizkit {
	class WindowImplement {
	public:
		virtual void Create(int width, int height, const std::string& windowName) = 0;
		
		virtual void SwapBuffers() = 0;
	};
}