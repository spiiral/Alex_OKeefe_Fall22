/*
    Include Lizkit.h
    Inerhit a class from LizkitApp. Override OnUpdate method.
    Use macro for class name
*/

#include "Lizkit.h"
#include "Counter.h"
#include "Unit.h"
#include <cmath>
#include <random>


class Game39541 : public Lizkit::LizkitApp {
   
public:
    void OnUpdate() override {
        if (mGameState == GameState::PLAYING) {
            if (mJumpState == CharState::JUMP) {
                mJumpTime++;
                mJumpPos = ((-0.45) * pow((mJumpTime - 30), 2)) + 500;
                mCharacter.SetY(mJumpPos);
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
          
            switch (mCarState) {
            case CarState::NORMAL:
                mCar.ChangeX(-mCarSpeed);
                break;

            case CarState::STOPFAST:
                if (mCar.GetX() >= 550) {
                    mCar.ChangeX(-mCarSpeed);
                }
                if (mCar.GetX() <= 550 && mCarTimer < 60) {
                    mCar.SetX(550);
                    mCarTimer++;
                }
                if (mCarTimer >= 60) {
                    mCar.ChangeX(1.3 * -mCarSpeed);
                }
                break;

            case CarState::SLOWFAST:
                if (mCar.GetX() >= 500) {
                    mCar.ChangeX(0.67 * -mCarSpeed);
                }
                else {
                    mCar.ChangeX(1.3 * -mCarSpeed);
                }
                break;

            case CarState::TRICK:
                if (mCar.GetX() >= 600) {
                    mCar.ChangeX(1.3 * -mCarSpeed);
                }
                else if (mCar.GetX() >= 400 && mCar.GetX() <= 600) {
                    mCar.ChangeX(0.67 * -mCarSpeed);
                }
                else {
                    mCar.ChangeX(1.3 * -mCarSpeed);
                }
                break;
                
            }
            if (mCar.OverlapsWith(mCharacter)) {
                mCharacter.ChangeHP(-1);
                mCar.ChangeHP(-1);
                mRoundLost = true;
            }
            if ((mCar.GetX()) + mCar.GetPicture().GetWidth() < -800 || mRoundLost) {
                mCarTimer = 0;
                mCar.SetX(1600);
                if (!mRoundLost) {
                    mIntCounter++;
                    if (mIntCounter % 3 == 0) {
                        mCarSpeed++;
                    }
                }
                switch (rand() %4) {
                case 0:
                    mCarState = CarState::NORMAL;
                    break;
                case 1:
                    mCarState = CarState::SLOWFAST;
                    break;
                case 2:
                    mCarState = CarState::STOPFAST;
                    break;
                case 3:
                    mCarState = CarState::TRICK;
                    break;
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

    int mCarTimer{ 0 };
    int mCarSpeed{ 10 };
    int mJumpPos{ 100 };
    int mJumpTime{ 0 };
    float mFallTime{ 0 };
    
    bool mRoundLost = false;
    int mIntCounter = 0;
    Counter mCountDrawer;

    enum class CarState {
        NORMAL,
        STOPFAST,
        SLOWFAST,
        TRICK
    }mCarState{CarState::NORMAL};
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
               mCharacter.SetHP(3);
               mCharacter.SetY(100);
               mCarSpeed = 10;
               mGameState = GameState::PLAYING;
               mJumpState = CharState::STILL;
               mIntCounter = 0;
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