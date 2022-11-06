#include "pch.h"

#include "LizkitApp.h"


namespace Lizkit {
    void LizkitApp::OnUpdate() {

    }

    void LizkitApp::Run() {
        int updateCount = 1;
        LIZKIT_LOG("Lizkit running.")
            while (true) {
                OnUpdate();
                updateCount++;
            }
    }
}