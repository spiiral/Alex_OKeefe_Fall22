/*
    Include Lizkit.h
    Inerhit a class from LizkitApp. Override OnUpdate method.
    Use macro for class name
*/

#include "Lizkit.h"
#include "Counter.h"
#include "Unit.h"
#include <cmath>


class Game39541 : public Lizkit::LizkitApp {
   
public:
    void OnUpdate() override {
        if (mJumpState == CharState::JUMP) {
            mJumpTime++;
            if (mJumpTime % 60 == 0) {
                LIZKIT_LOG("one second has passed")
            }
            mJumpPos += 10;
            mCharacter.SetY(mJumpPos);

            if (mJumpPos >= 400) {
                mJumpPos = 400;
                mJumpState = CharState::FALL;
            }
            if (mJumpPos <= 100) {
                mJumpPos == 100;
                mJumpState = CharState::STILL;
            }
        }
        if (mJumpState == CharState::FALL) {
            mJumpPos -= 10;
            mCharacter.SetY(mJumpPos);
            if (mCharacter.GetY() <= 100) {
                mCharacter.SetY(100);
                mJumpState = CharState::STILL;
            }
        }
        if (mState == CharState::MOVE_RIGHT) {
          //  if(mCharacter.GetX() > 0)
            mCharacter.ChangeX(8);
        }
        if (mState == CharState::MOVE_LEFT) {
            mCharacter.ChangeX(-8);
        }
        mCar.ChangeX(-20);
        if(mCar.OverlapsWith(mCharacter)) {
            mRoundLost = true;
        }
        if ((mCar.GetX()) + mCar.GetPicture().GetWidth() < -800) {
            mCar.SetX(800);
            if (!mRoundLost) {
                mIntCounter++;
            }
            mRoundLost = false;
        }
        Lizkit::Renderer::Draw(mBackground, -500, -600, 1);
        Lizkit::Renderer::Draw(mCharacter.GetPicture(), mCharacter.GetX(), mCharacter.GetY(), 1);
        Lizkit::Renderer::Draw(mCar.GetPicture(), mCar.GetX(), mCar.GetY(), 1);
        mCountDrawer.DrawCounter(mIntCounter);
        
    }

    Game39541() {
        Lizkit::LizkitWindow::GetWindow()->SetKeyPressedCallback(
            [this](const Lizkit::KeyPressedEvent& event) {OnKeyPress(event); });
        Lizkit::LizkitWindow::GetWindow()->SetKeyReleasedCallback(
            [this](const Lizkit::KeyReleasedEvent& event) {OnKeyRelease(event); });
    }
    

private:
    
    Lizkit::Picture mBackground{ "Assets/Textures/background.png" };
    Lizkit::Unit mCharacter{ "Assets/Textures/test.png", 1, 100, 100 };
    Lizkit::Unit mCar{ "Assets/Textures/car.png", 1, 900, 75};

    int mScore{ 0 };
    int mFrames{ 0 };

    int mJumpPos{ 100 };
    int mJumpTime{ 0 };
    float mFallTime{ 0 };
    std::pair<int, int> charPos = std::make_pair(100, 100);
    std::pair<int, int> enemyPos = std::make_pair(900, 75);

    bool mRoundLost = false;
    int mIntCounter = 0;
    Counter mCountDrawer;

    enum class CharState {
        MOVE_LEFT,
        MOVE_RIGHT,
        JUMP,
        FALL,
        STILL
    } mState{ CharState::STILL }, mJumpState{ CharState::STILL };

    void OnKeyPress(const Lizkit::KeyPressedEvent& event) {
        switch (event.GetKeyCode()) {
        case LIZKIT_KEY_LEFT:
            mState = CharState::MOVE_LEFT;
            break;
        case LIZKIT_KEY_RIGHT:
            mState = CharState::MOVE_RIGHT;
            break;
        case LIZKIT_KEY_SPACE:
            if (mJumpState == CharState::STILL) {
                mJumpTime = 0;
                mJumpState = CharState::JUMP;
            }
            break;

        }
    }
    void OnKeyRelease(const Lizkit::KeyReleasedEvent& event) {
        switch (event.GetKeyCode()) {
        case LIZKIT_KEY_LEFT:
            mState = CharState::STILL;
            break;
        case LIZKIT_KEY_RIGHT:
            mState = CharState::STILL;
            break;
        case LIZKIT_KEY_SPACE:
            break;
        }
    }
};
START_LIZKIT_GAME(Game39541)