#ifndef __RUNNINGPLAYER_H__
#define __RUNNINGPLAYER_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"
#include "Player.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class RunningPlayer : public Sprite
{
public:
    RunningPlayer(const Window &window, const int &direction);
    ~RunningPlayer();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;

private:
    Rect src;
    int direction;
};

#endif
