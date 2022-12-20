#pragma once

#include "pch.h"

namespace Lizkit {
	class PictureImplement {
	public:
		virtual int GetHeight() const = 0;
		virtual int GetWidth() const = 0;

		virtual void Activate() = 0;
	};
}