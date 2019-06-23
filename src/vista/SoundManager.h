#ifndef PORTAL_SOUNDMANAGER_H
#define PORTAL_SOUNDMANAGER_H

#include <queue>
#include <map>

class SoundManager {
    std::queue<int> soundsid;
    std::map<int,int> soundslvl;
public:
    SoundManager();
    void addSoundtoPlay(int soundid);
    void playSound();
};


#endif
