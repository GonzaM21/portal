#ifndef __CLOSEDGATE_H__
#define __CLOSEDGATE_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"


class ClosedGate : public Sprite
{
public:
    ClosedGate(const Window &window, const int &code);
    ~ClosedGate();
    virtual int render(const Rect &dest);
    virtual void setSrc(Rect &src) override;
    virtual Rect getSrc() override { return src; };

private:
    Rect src;
    int y_position;
};

#endif
