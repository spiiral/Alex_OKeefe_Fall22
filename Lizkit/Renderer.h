#pragma once

#include "LizkitUtil.h"
#include "Shader.h"
#include "Picture.h"
#include "RendererImplement.h"

namespace Lizkit {
	class LIZKIT_API Renderer {
	public:
		static void Init();
		
		static Renderer* GetRenderer();

		static void Draw(Picture& picture, int x, int y, int z);

		static void Draw(Picture& picture, int x, int y, int z, Shader& shader);

		static void Clear();
	private:
		inline static Renderer* mInstance{ nullptr };

		RendererImplement* mImplement;

		Renderer();

		Shader mDefaultShader{ "../Game39541/Assets/Shaders/defaultLizkitVertex.glsl", 
							 "../Game39541/Assets/Shaders/defaultLizkitFragment.glsl"};

	};
}