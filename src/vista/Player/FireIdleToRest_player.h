#ifndef __FIREIDLETOREST #define __FIREIDLE &window) YER_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

#include "Player.h"

/*Estado de la clase Player, hereda de State */
class FireIdleToRestPlayer : public Sprite
{
public:
    FireIdleToRestPlayer(const Window &window, const int &direction);
    ~FireIdleToRestPlayer();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual bool isDone() override;

private:
    Rect src;
    bool done;
    int direction;
};

#endif
