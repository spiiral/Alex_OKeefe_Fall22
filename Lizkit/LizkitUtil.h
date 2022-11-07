#pragma once

#define START_LIZKIT_GAME(GameClass) \
    int main(){ \
        GameClass lizkitGame; \
        lizkitGame.Run(); \
        return 0; \
    }

#ifdef LIZKIT_WINDOWS
    #ifdef LIZKIT_LIB
        #define LIZKIT_API __declspec(dllexport)
    #else
        #define LIZKIT_API __declspec(dllimport)
    #endif
#else
    #define LIZKIT_API
#endif

#ifdef LIZKIT_DEBUG
    #define LIZKIT_LOG(x) std::cout<<x<<std::endl;
#else
    #define LIZKIT_LOG(x)
#endif