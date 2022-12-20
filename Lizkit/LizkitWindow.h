#pragma once

#include "pch.h"
#include "LizkitUtil.h"
#include "WindowImplement.h"
#include "Event.h"

namespace Lizkit{
	class LIZKIT_API LizkitWindow {
	public:
		static void Init();
		static LizkitWindow* GetWindow();

		virtual void Create(int width, int height, const std::string & windowName);

		virtual void SwapBuffers();

		int GetWidth() const;
		int GetHeight() const;

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyPressedCallback);

	private:
		inline static LizkitWindow* mInstance{ nullptr };

		WindowImplement* mImplement{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};

}
