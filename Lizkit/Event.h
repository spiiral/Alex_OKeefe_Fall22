#pragma once

#include "LizkitUtil.h"

namespace Lizkit {
	class LIZKIT_API KeyPressedEvent {
	public:
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class LIZKIT_API KeyReleasedEvent{
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};
}
