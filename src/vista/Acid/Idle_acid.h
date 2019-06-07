#ifndef __IDLEACID_H__
#define __IDLEACID_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class IdleAcid : public Sprite
{
public:
    IdleAcid(const Window &window);
    ~IdleAcid();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;

private:
    Rect src;
};

#endif
