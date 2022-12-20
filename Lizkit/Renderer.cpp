#include "pch.h"

#include "Renderer.h"
#include "OpenGLCode/OpenGLRenderer.h"

namespace Lizkit {
	void Renderer::Init() {
		if (mInstance == nullptr)
			mInstance = new Renderer;
	}

	Renderer* Renderer::GetRenderer(){
		return mInstance;
	}
	void Renderer::Draw(Picture& picture, int x, int y, int z) {
		GetRenderer()->mImplement->Draw(picture, x, y, z, GetRenderer()->mDefaultShader);
	}

	void Renderer::Draw(Picture& picture, int x, int y, int z, Shader& shader){
		GetRenderer()->mImplement->Draw(picture, x, y, z, shader);
	}

	void Renderer::Clear(){
		GetRenderer()->mImplement->Clear();
	}

	Renderer::Renderer() {
#ifdef LIZKIT_OPENGL
		mImplement = new OpenGLRenderer{ };
#else 
		#OpenGL_is_the_only_option_right_now
#endif
	}
}