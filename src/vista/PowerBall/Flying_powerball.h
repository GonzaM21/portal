#ifndef __FLYINGPOWERBALL_H__
#define __FLYINGPOWERBALL_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"


class FlyingPowerBall : public Sprite
{
public:
    FlyingPowerBall(const Window &window,const int& direction);
    ~FlyingPowerBall();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual bool isDone() override;
    void setState(const int &state, const int &direction);

private:
    Rect src;
    bool done = false;
    int direction;
    int state;
};

#endif
