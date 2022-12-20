#pragma once

#include "LizkitUtil.h"
#include "ShaderImplement.h"
#include "pch.h"

namespace Lizkit {
	class LIZKIT_API Shader {
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentShader);
		Shader(std::string&& vertexFile, std::string&& fragmentShader);

		void Activate();

		void ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals);
		void ProvideFloatValues(std::string&& valueName, std::vector<float>&& vals);

	private:
		ShaderImplement* mImplement{nullptr};
	};
}