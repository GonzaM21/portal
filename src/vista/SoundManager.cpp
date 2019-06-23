#include "SoundManager.h"
#include "Constants.h"
#include "MusicBase.h"

SoundManager::SoundManager() {
    soundslvl[AMBIENT_MUSIC_ID] = 40;
    soundslvl[CHELL_STEP_FX_ID] = 20;
    soundslvl[CHELL_JUMP_FX_ID] = 20;
    soundslvl[ENERGY_BALL_FX_ID] = 20;
    soundslvl[GATE_FX_ID] = 20;
    soundslvl[PORTAL_SHOT_FX_ID] = 20;
    soundslvl[ROCK_DEAD_FX_ID] = 20;
    soundslvl[CHELL_SCREAM_ID] = 20;
}


void SoundManager::addSoundtoPlay(int soundid) {
    if(soundslvl.find(soundid) == soundslvl.end()) return;
    soundsid.push(soundid);
}

void SoundManager::playSound(){
    int id = soundsid.front();
    MusicBase::getInstance()->playMusic(id,soundslvl[id]);
    soundsid.pop();
}