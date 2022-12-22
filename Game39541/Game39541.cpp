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
        if (mGameState == GameState::PLAYING) {
            if (mJumpState == CharState::JUMP) {
                mJumpTime++;
                if (mJumpTime % 60 == 0) {
                    LIZKIT_LOG("one second has passed")
                }
                mJumpPos = ((-0.45) * pow((mJumpTime - 30), 2)) + 500;
                mCharacter.SetY(mJumpPos);

                LIZKIT_LOG(mJumpPos)

                    if (mJumpPos <= 100) {
                        mJumpPos == 100;
                        mJumpState = CharState::STILL;
                    }
            }

            if (mState == CharState::MOVE_RIGHT) {
                if (mCharacter.GetX() + mCharacter.GetPicture().GetWidth() < 1000)
                    mCharacter.ChangeX(8);
            }
            if (mState == CharState::MOVE_LEFT) {
                if (mCharacter.GetX() > 0)
                    mCharacter.ChangeX(-8);
            }
            mCar.ChangeX(-mCarSpeed);
            if (mCar.OverlapsWith(mCharacter)) {
                mCharacter.ChangeHP(-1);
                mCar.ChangeHP(-1);
                mRoundLost = true;
            }
            if ((mCar.GetX()) + mCar.GetPicture().GetWidth() < -800 || mRoundLost) {
                mCar.SetX(1600);
                if (!mRoundLost) {
                    mIntCounter++;
                    if (mIntCounter % 3 == 0) {
                        mCarSpeed++;
                    }
                }
                mRoundLost = false;
            }
            if (mCharacter.GetHP() <= 0) {
                mGameState = GameState::LOST;
            }

            Lizkit::Renderer::Draw(mBackground, -500, -600, 1);
            Lizkit::Renderer::Draw(mCharacter.GetPicture(), mCharacter.GetX(), mCharacter.GetY(), 1);
            Lizkit::Renderer::Draw(mCar.GetPicture(), mCar.GetX(), mCar.GetY(), 1);
            mCountDrawer.DrawCounter(mIntCounter);
            int xTemp = 50;
            for (int i = 0; i < mCharacter.GetHP(); i++) {
                Lizkit::Renderer::Draw(mCharacter.GetPicture(), xTemp + (100 * i), 700, 1);
            }
        }
        
        if (mGameState == GameState::LOST) {
            Lizkit::Renderer::Draw(mLossScreen, -500, -600, 1);
            mCountDrawer.DrawCounter(mIntCounter);
        }
        
    }

    Game39541() {
        Lizkit::LizkitWindow::GetWindow()->SetKeyPressedCallback(
            [this](const Lizkit::KeyPressedEvent& event) {OnKeyPress(event); });
        Lizkit::LizkitWindow::GetWindow()->SetKeyReleasedCallback(
            [this](const Lizkit::KeyReleasedEvent& event) {OnKeyRelease(event); });
    }
    

private:
    
    Lizkit::Picture mLossScreen{ "Assets/Textures/loss.png" };
    Lizkit::Picture mBackground{ "Assets/Textures/background.png" };
    Lizkit::Unit mCharacter{ "Assets/Textures/test.png", 3, 100, 100 };
    Lizkit::Unit mCar{ "Assets/Textures/car.png", 1, 900, 75};

    int mScore{ 0 };
    int mFrames{ 0 };

    int mCarSpeed{ 10 };
    int mJumpPos{ 100 };
    int mJumpTime{ 0 };
    float mFallTime{ 0 };
    std::pair<int, int> charPos = std::make_pair(100, 100);
    std::pair<int, int> enemyPos = std::make_pair(900, 75);

    bool mRoundLost = false;
    int mIntCounter = 0;
    Counter mCountDrawer;

    enum class GameState {
        PLAYING,
        LOST
    }mGameState{GameState::PLAYING};

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
        case LIZKIT_KEY_ENTER:
           if (mGameState == GameState::LOST) {
               mIntCounter = 0;
               mCharacter.SetHP(3);
               mGameState = GameState::PLAYING;
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