#ifndef __DANCINGPLAYER_H__
#define __DANCINGPLAYER_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

#include "Player.h"

/*Estado de la clase Player, hereda de Sprite */
class DancingPlayer : public Sprite
{
public:
    DancingPlayer(const Window &window, const int &direction, const int& id);
    ~DancingPlayer();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual void setDirection(const int &direction){this->direction = direction;};

private:
    Rect src;
    int direction;
    int id;
};

#endif
