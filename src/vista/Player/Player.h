#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Camara.h"
#include "../Sprite.h"
#include <map>
#include <unordered_map>

class Player
{
public:
  Player(const Window &window, const int &direction);
  ~Player();
  int render(Camara &camara);
  void setIdle();
  void setFlying();
  void setGrabbed();
  void setDying();
  void setRestIdle();
  void setRunning();
  void setDancing();
  void setRunningShooting();
  void setStop();
  void setRising();
  void setFalling();
  void open();
  void close();
  bool isOpen();
  bool isClosed();
  void setSrc(int x, int y, int widht, int heigh);
  void setDestWorld(float x, float y, float widht, float heigh);
  void setDestScreen(int x, int y, int widht, int heigh);
  Rect getSrc();
  Rect getDest();
  Rect getDestWorld() { return dest_world; };
  void setState(const int &state, const int &direction);

private:
  Rect dest_world;
  Sprite *sprite;
  Window window;
  bool is_open = false;
  bool is_closed = true;
  int direction;
  typedef void (Player::*player_method_t)();
  std::unordered_map<int, player_method_t> changeState;
  std::unordered_map<int, Sprite *> states;
};

#endif
