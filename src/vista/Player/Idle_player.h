#ifndef __IDLEPLAYER_H__
#define __IDLEPLAYER_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Window.h"
#include "../Rect.h"

#include "Player.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class IdlePlayer : public Sprite
{
public:
    IdlePlayer(const Window &window, const int &direction);
    ~IdlePlayer();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual void setDirection(const int &direction) { this->direction = direction; };

private:
    Rect src;
    int direction;
};

#endif
