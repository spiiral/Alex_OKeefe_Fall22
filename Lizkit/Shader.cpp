#include "pch.h"

#include "Shader.h"
#include "OpenGLCode/OpenGLShader.h"

namespace Lizkit {
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile) {
#ifdef LIZKIT_OPENGL
		mImplement = new OpenGLShader{vertexFile, fragmentFile};
#else 
		#OpenGL_is_the_only_option_right_now
#endif
	}
	Shader::Shader(std::string&& vertexFile, std::string&& fragmentFile) {
#ifdef LIZKIT_OPENGL
		mImplement = new OpenGLShader{vertexFile, fragmentFile};
#else 
		#OpenGL_is_the_only_option_right_now
#endif
	}

	void Shader::Activate() {
		mImplement->Activate();
	}
	void Shader::ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals){
		mImplement->ProvideFloatValues(valueName, vals);
	}
	
	void Shader::ProvideFloatValues(std::string&& valueName, std::vector<float>&& vals) {
		mImplement->ProvideFloatValues(valueName, vals);
	}
}