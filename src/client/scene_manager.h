#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include "../vista/ModelFacade.h"
#include "../vista/next_level_screen/EndLevelScreen.h"
#include <string>
#include <vector>
#define GAME_SCREEN 0
#define END_LEVEL_SCREEN 1
#define EXIT_GAME_SCREEN 2


class SceneManager {
private: 
    Window window;
    ModelFacade model_facade;
    EndLevelScreen end_level_screen;
    int actual_screen;
    void setActualScreen(int screen_num);
public:
    SceneManager();
    ~SceneManager() = default;
    void renderAll();
    void decodeObjectMessage(std::vector<std::string> &arguments);
    ModelFacade *getModelFacade();
    void putNextLevelScene(); 
    void putGameScene();
    int getActualScreen();
    EndLevelScreen *getEndLevelScreen();
};

#endif