#include"pch.h"

#include "LizkitWindow.h"
#include "WindowImplement.h"
#include "GLFWcode/GLFWimplement.h"

namespace Lizkit {
	void LizkitWindow::Init(){
		if (mInstance == nullptr) {
			mInstance = new LizkitWindow;
#ifdef LIZKIT_WINDOWS
			mInstance->mImplement = new GLFWimplement;
#elif defined LIZKIT_MAC
			mInstance - mImplement = new GLFWimplement;
#else
			mInstance - mImplement = new GLFWimplement;
#endif
		}
	}
	LizkitWindow* LizkitWindow::GetWindow() {
		return mInstance;
	}

	void LizkitWindow::Create(int width, int height, const std::string& windowName) {
		mImplement->Create(width, height, windowName);
	}

	void LizkitWindow::SwapBuffers() {
		mImplement->SwapBuffers();
	}
}