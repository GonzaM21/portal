#ifndef __ORANGEPORTAL_H__
#define __ORANGEPORTAL_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class OrangePortal : public Sprite
{
public:
  OrangePortal(const Window &window, const int &direction);
  ~OrangePortal();
  virtual int render(const Rect &dest);
  virtual void setSrc(Rect &src) override;
  virtual bool isDone() override;

private:
  Rect src;
  bool done = false;
  int direction;
};

#endif
