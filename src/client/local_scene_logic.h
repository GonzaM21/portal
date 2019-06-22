#ifndef LOCAL_SCENE_LOGIC_H
#define LOCAL_SCENE_LOGIC_H
#include "scene_manager.h"

class LocalSceneLogic {
private:
    SceneManager &scene_manager;
    bool end_game;
    bool next_level;
public:
    LocalSceneLogic(SceneManager &scene_manager);
    ~LocalSceneLogic() = default;
    void getClickEvent(int x, int y);
    bool getEndGame();
    bool getNextLevel();
    void resetLocalSceneLogic();    
};

#endif