#ifndef __BUTTON_H__
#define __BUTTON_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Sprite.h"
#include "../Camara.h"
#include <unordered_map>

class Button
{
public:
  Button(const Window &window, const int &state);
  ~Button();
  int render(Camara &camara);
  void setPressed();
  void setUnpressed();
  void setDestWorld(float x, float y, float widht, float heigh);
  Rect getDestWorld() { return dest_world; };
  void setState(const int state);

private:
  Rect dest_world;
  Sprite *sprite;
  Window window;
  typedef void (Button::*button_method_t)();
  std::unordered_map<int, button_method_t> changeState;
  std::unordered_map<int, Sprite *> states;
};

#endif
