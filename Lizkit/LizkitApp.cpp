#include "pch.h"

#include "LizkitApp.h"
#include "LizkitWindow.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Picture.h"
#include "Renderer.h"
#include <iostream>

namespace Lizkit {
    LizkitApp::LizkitApp() {
        LizkitWindow::Init();
        LizkitWindow::GetWindow()->Create(1000, 800, "TestWindow");

        Renderer::Init();
    }

    void LizkitApp::OnUpdate() {
        
    }

    void LizkitApp::Run() {
        LIZKIT_LOG("Lizkit running.")

       mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

       Picture pic{ "Assets/Textures/test.png" };

        while (true) {
            Renderer::Clear();

            OnUpdate();

            std::this_thread::sleep_until(mNextFrameTime);

            LizkitWindow::GetWindow()->SwapBuffers();

            mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
        }
          
    }
    
}
