#ifndef __RESTINGIDLEPLAYER_H__
#define __RESTINGIDLEPLAYER_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

#include "Player.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class RestingIdlePlayer : public Sprite
{
public:
    RestingIdlePlayer(const Window &window, const int &direction);
    ~RestingIdlePlayer();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;

private:
    Rect src;
    int direction;
};

#endif
