#pragma once

#include "pch.h"
#include "LizkitUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace Lizkit {

    class LIZKIT_API LizkitApp {
    public:
        LizkitApp();
        virtual void OnUpdate();
        void Run();

    private:
        std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FRAMES_PER_SECOND };
        std::chrono::steady_clock::time_point mNextFrameTime;
    };
}