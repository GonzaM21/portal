#ifndef __OPENINGGATE_H__
#define __OPENINGGATE_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

#include "Gate.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class OpeningGate : public Sprite
{
public:
    OpeningGate(const Window &window, const int &code);
    ~OpeningGate();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual bool isDone() override;
    virtual Rect getSrc() override { return src; };
    virtual void restart();

private:
    Rect src;
    bool done = false;
    int y_position;
};

#endif
