#pragma once

#include"pch.h"
#include "LizkitUtil.h"
#include "PictureImplement.h"

namespace Lizkit{
	class LIZKIT_API Picture{
	public:
		Picture(const std::string& sourceFile);
		Picture(std::string&& sourceFile);

		int GetHeight() const;
		int GetWidth() const;

		void Activate();
	private:
		PictureImplement* mImplement{ nullptr };
	};
}