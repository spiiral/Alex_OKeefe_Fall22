#include "pch.h"

#include "LizkitApp.h"
#include "LizkitWindow.h"



namespace Lizkit {
    void LizkitApp::OnUpdate() {

    }

    void LizkitApp::Run() {

        LIZKIT_LOG("Lizkit running.")

        LizkitWindow::Init();
        LizkitWindow::GetWindow()->Create(600, 400, "Test");
            while (true) {
                 LizkitWindow::GetWindow()->SwapBuffers();

                 OnUpdate();
            }
          
    }
    
}
