#include "MusicBase.h"
#include "Constants.h"

MusicBase::MusicBase() {
    createMusic(AMBIENT_MUSIC_ID,AMBIENT_MUSIC);
    createMusic(CHELL_STEP_FX_ID,CHELL_STEP_FX);
    createMusic(CHELL_JUMP_FX_ID,CHELL_JUMP_FX);
    createMusic(ENERGY_BALL_FX_ID,ENERGY_BALL_FX);
    createMusic(GATE_FX_ID,GATE_FX);
    createMusic(PORTAL_SHOT_FX_ID,PORTAL_SHOT_FX);
    createMusic(ROCK_DEAD_FX_ID,ROCK_DEAD_FX);
    createMusic(CHELL_SCREAM_ID,CHELL_SCREAM);
}

void MusicBase::createMusic(const int &id, const std::string filename) {
    if (music.find(id) != music.end()) return;
    std::cout << "Creado " << id << " file " << filename << std::endl;
    music[id] = Mix_LoadMUS(filename.c_str());
}

Mix_Music* MusicBase::getMusic(const int &id) {
    return music[id];
}

MusicBase *MusicBase::instance = NULL;

MusicBase::~MusicBase() {
    for (auto &sound : music)
    {
        Mix_FreeMusic(sound.second);
    }
}