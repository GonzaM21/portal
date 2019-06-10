#ifndef __DYINGPLAYER_H__
#define __DYINGPLAYER_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

#include "Player.h"

/*Estado de la clase Player, hereda de State */
class DyingPlayer : public Sprite
{
public:
    DyingPlayer(const Window &window, const int &direction);
    ~DyingPlayer();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual bool isDone() override;
    virtual void setDirection(const int &direction) { this->direction = direction; };

private:
    Rect src;
    bool done;
    int direction;
};

#endif
