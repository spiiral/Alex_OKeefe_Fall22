#pragma once
#include "pch.h"

#include "LizkitUtil.h"
#include "WindowImplement.h"

namespace Lizkit{
	class LIZKIT_API LizkitWindow {
	public:
		static void Init();
		static LizkitWindow* GetWindow();

		void Create(int width, int height, const std::string & windowName);

		void SwapBuffers();

	private:

		inline static LizkitWindow* mInstance{ nullptr };

		WindowImplement* mImplement{ nullptr };

	};

}
