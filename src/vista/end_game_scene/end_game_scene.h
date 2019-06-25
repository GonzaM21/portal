#ifndef END_GAME_SCREEN_H
#define END_GAME_SCREEN_H
#include "../Window.h"

class EndGameScene {
private:
    Window window;
public:
    EndGameScene(Window &window);
    ~EndGameScene() = default;
    void renderScene();
};

#endif