#ifndef __GATE_H__
#define __GATE_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Sprite.h"
#include "../Camara.h"
#include <unordered_map>

class Gate
{
public:
  Gate(const Window &window, const int &code);
  ~Gate();
  int render(Camara &camara);
  void setOpen();
  void setClosed();
  void setOpening();
  void setClosing();
  bool isOpen();
  bool isClosed();
  void setDestWorld(float x, float y, float widht, float heigh);
  Rect getDestWorld() { return dest_world; };
  void setState(const int &state);

private:
  Rect dest_world;
  Sprite *sprite;
  Window window;
  bool is_open = false;
  bool is_closed = true;
  int code;
  typedef void (Gate::*gate_method_t)();
  std::unordered_map<int, gate_method_t> changeState;
  std::unordered_map<int, Sprite *> states;
};

#endif
