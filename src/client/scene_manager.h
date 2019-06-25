#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include "../vista/ModelController.h"
#include "../vista/next_level_screen/EndLevelScreen.h"
#include "../vista/end_game_scene/end_game_scene.h"
#include "ffmpeg/ffmpeg.h"
#include <string>
#include <vector>
#define GAME_SCREEN 0
#define END_LEVEL_SCREEN 1
#define EXIT_GAME_SCREEN 2


class SceneManager {
private: 
    Window window;
    ModelController model_controller;
    EndLevelScreen end_level_scene;
    EndGameScene end_game_scene;
    Ffmpeg ffmpeg;
    int actual_screen;
    bool level_change;
    bool recording;
    bool full_screen;
    void setActualScreen(int screen_num);
public:
    SceneManager();
    ~SceneManager() = default;
    void renderAll();
    void decodeObjectMessage(std::vector<std::string> &arguments);
    ModelController *getModelController();
    void putNextLevelScene(); 
    void putGameScene();
    void putEndGameScene();
    int getActualScreen();
    void resetLevelStage();
    void setFullScreen();
    void record();  
    void stopRocording();
};

#endif