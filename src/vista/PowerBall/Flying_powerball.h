#ifndef __FLYINGPOWERBALL_H__
#define __FLYINGPOWERBALL_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"
#include "Paw_powerball.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class FlyingPowerBall : public Sprite
{
public:
    FlyingPowerBall(const Window &window,const int& direction);
    ~FlyingPowerBall();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual bool isDone() override;

private:
    Rect src;
    bool done = false;
    const int direction;
    // PawPowerBall paw;
};

#endif
