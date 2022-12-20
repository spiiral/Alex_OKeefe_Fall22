#pragma once

#include "../RendererImplement.h"

namespace Lizkit {
	class OpenGLRenderer : public RendererImplement {
	public:
		OpenGLRenderer();

		virtual void Draw(Picture& picture, int x, int y, int z, Shader& shader) override;
		virtual void Clear() override;
	};
}