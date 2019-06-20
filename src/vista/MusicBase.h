#ifndef PORTAL_MUSICBASE_H
#define PORTAL_MUSICBASE_H

#include <SDL2/SDL_mixer.h>

class MusicBase {
    std::map<int, Mix_music*> music;
    static MusicBase *instance;
public:
    static MusicBase *getInstance(){
        if (instance == NULL)
            instance = new MusicBase();
        return instance;
    }

    MusicBase();
    void createMusic(const int &id, const std::string filename);
    Mix_Music * getMusic(const int &id);

    virtual ~MusicBase();

    MusiceBase(MusicBase const &);
    MusicBase &operator=(MusicBase const &);
};


#endif