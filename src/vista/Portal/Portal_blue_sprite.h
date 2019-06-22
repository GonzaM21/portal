#ifndef __BLUEPORTAL_H__
#define __BLUEPORTAL_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class BluePortal : public Sprite
{
public:
  BluePortal(const Window &window, const int &direction);
  ~BluePortal();
  virtual int render(const Rect &dest);
  virtual void setSrc(Rect &src) override;
  virtual bool isDone() override;
  virtual void setDirection(const int &direction) override;

private:
  Rect src;
  bool done = false;
  int direction;
};

#endif
