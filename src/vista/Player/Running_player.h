#ifndef __RUNNINGPLAYER_H__
#define __RUNNINGPLAYER_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"
#include "Player.h"


class RunningPlayer : public Sprite
{
public:
    RunningPlayer(const Window &window, const int &direction, const int& id);
    ~RunningPlayer();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual void setDirection(const int &direction) { this->direction = direction; };

private:
    Rect src;
    int direction;
    int id;
};

#endif
