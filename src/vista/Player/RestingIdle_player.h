#ifndef __RESTINGIDLEPLAYER_H__
#define __RESTINGIDLEPLAYER_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

#include "Player.h"


class RestingIdlePlayer : public Sprite
{
public:
    RestingIdlePlayer(const Window &window, const int &direction, const int& id);
    ~RestingIdlePlayer();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual void setDirection(const int &direction) { this->direction = direction; };

private:
    Rect src;
    int direction;
    int id;
};

#endif
