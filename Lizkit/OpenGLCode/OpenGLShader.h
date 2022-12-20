#pragma once

#include "../ShaderImplement.h"

namespace Lizkit {
	class OpenGLShader : public ShaderImplement {
	public:
		OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile);
		OpenGLShader(std::string&& vertexFile, std::string&& fragmentFile);
		~OpenGLShader();

		virtual void Activate() override;

		virtual void ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals) override;
		virtual void ProvideFloatValues(std::string&& valueName, const std::vector<float>& vals) override;

	private:
		unsigned int mShaderProg{ 0 };
	};
}
