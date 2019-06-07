#ifndef __OPENGATE_H__
#define __OPENGATE_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

#include "Gate.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class OpenGate : public Sprite
{
public:
    OpenGate(const Window &window, const int &code);
    ~OpenGate();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual Rect getSrc() override { return src; };

private:
    Rect src;
};

#endif
