#ifndef PORTAL_MUSICBASE_H
#define PORTAL_MUSICBASE_H

#include <SDL2/SDL_mixer.h>
#include "Constants.h"
#include <map>

class MusicBase {
    std::map<int, Mix_Chunk*> music;
    static MusicBase *instance;
public:
    static MusicBase *getInstance(){
        if (instance == NULL)
            instance = new MusicBase();
        return instance;
    }

    MusicBase();
    void createMusic(const int &id, const std::string filename);
    Mix_Chunk * getMusic(const int &id);

    virtual ~MusicBase();

    MusicBase(MusicBase const &);
    MusicBase &operator=(MusicBase const &);
    void playMusic(const int &id, const int &lvl);
};


#endif