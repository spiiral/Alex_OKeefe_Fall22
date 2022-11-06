#pragma once

#include "LizkitUtil.h"

namespace Lizkit {

    class LIZKIT_API LizkitApp {
    public:
        virtual void OnUpdate();
        void Run();
    };
}