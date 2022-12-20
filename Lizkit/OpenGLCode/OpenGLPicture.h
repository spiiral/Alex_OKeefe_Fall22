#pragma once

#include "../PictureImplement.h"

namespace Lizkit {
	class OpenGLPicture : public PictureImplement {
	public:
		OpenGLPicture(const std::string& pictureFile);
		OpenGLPicture(std::string&& pictureFile);

		~OpenGLPicture();

		virtual int GetHeight() const override;
		virtual int GetWidth() const override;

		virtual void Activate() override;

	private:
		unsigned int mImage{ 0 };
		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}