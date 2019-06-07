#ifndef __PAWPOWERBALL_H__
#define __PAWPOWERBALL_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class PawPowerBall : public Sprite
{
public:
    PawPowerBall(const Window &window);
    ~PawPowerBall();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual bool isDone() override;

private:
    Rect src;
    bool done;
};

#endif
