/*
    Include Lizkit.h
    Inerhit a class from LizkitApp. Override OnUpdate method.
    Use macro for class name
*/

#include "Lizkit.h"
#include "Counter.h"
#include "Unit.h"


class Game39541 : public Lizkit::LizkitApp {
   
public:
    void OnUpdate() override {
        if (mJumpState == CharState::JUMP) {
            if (mCharacter.GetY() == 100) {
                mJumpSpeed = 10;
            }
            else {
                mJumpSpeed = 10 - (1*(mCharacter.GetY()/50));
            }
            mCharacter.ChangeY(mJumpSpeed);
            if (mCharacter.GetY() >= 400) {
                mJumpState = CharState::FALL;
            }
        }
        if (mJumpState == CharState::FALL) {
            mJumpSpeed = 0 - (1 + (1400/mCharacter.GetY()));
            mCharacter.ChangeY(mJumpSpeed);
            if (mCharacter.GetY() <= 100) {
                mCharacter.SetY(100);
                mJumpState = CharState::STILL;
            }
        }
        if (mState == CharState::MOVE_RIGHT) {
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

    int mJumpSpeed{ 10 };
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