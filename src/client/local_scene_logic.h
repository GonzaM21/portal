#ifndef LOCAL_SCENE_LOGIC_H
#define LOCAL_SCENE_LOGIC_H
#include "scene_manager.h"
#include <mutex>

class LocalSceneLogic {
private:
    SceneManager &scene_manager;
    bool end_game;
    bool next_level;
    std::mutex m;
public:
    LocalSceneLogic(SceneManager &scene_manager);
    ~LocalSceneLogic() = default;
    void setEvent(std::string &event);
    bool getEndGame();
    bool getNextLevel();
    void resetLocalSceneLogic();    
};

#endif