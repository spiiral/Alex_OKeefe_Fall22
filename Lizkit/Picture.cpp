#include "pch.h"

#include "OpenGLCode/OpenGLPicture.h"
#include "Picture.h"


namespace Lizkit {

	Picture::Picture(const std::string& sourceFile) {
#ifdef LIZKIT_OPENGL
		mImplement = new OpenGLPicture{ sourceFile };
#else 
		#OpenGL_is_the_only_option_right_now
#endif
	}

	Picture::Picture(std::string&& sourceFile){
#ifdef LIZKIT_OPENGL
		mImplement = new OpenGLPicture{ sourceFile };
#else 
		#OpenGL_is_the_only_option_right_now
#endif
	}
	int Picture::GetHeight() const {
		return mImplement->GetHeight();
	}
	int Picture::GetWidth() const {
		return mImplement->GetWidth();
	}
	void Picture::Activate() {
		mImplement->Activate();
	}
}