#ifndef __TOUCHEDACID_H__
#define __TOUCHEDACID_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class TouchedAcid : public Sprite
{
public:
    TouchedAcid(const Window &window);
    ~TouchedAcid();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual bool isDone() override;

private:
    Rect src;
    bool done = false;
};

#endif
