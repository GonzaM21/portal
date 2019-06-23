#ifndef __GATE_H__
#define __GATE_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Sprite.h"
#include "../Camara.h"
#include <unordered_map>

/**
 * Clase Gate, la cual es el objeto que posee el sprite correspondiente y su posicion en el mundo real
*/
class Gate {
public:
  /**
   * Constructor, crea el sprite y setea el destWorld, y 
   * recibe un codigo que indica que puerta es
  */
  Gate(const Window &window, const int &code);

  /**
   * Destructor
  */
  ~Gate();
  
  /**
  * Metodo encargado de renderizar el sprite correspondiente
  */

  int render(Camara &camara);
  /**
  * Metodo encargado de setear el area y la posicion del objeto en el mundo real
  */
  void setDestWorld(float x, float y, float widht, float heigh);

  /**
  * Getter de la posicion del objeto en el mundo real
  */
  Rect getDestWorld() { return dest_world; };

  /**
  * Metodo encargado de setaer el estado del objeto recibido por parametro con un id
  */
  void setState(const int &state);

  /**
   * Setters de estados de la gate
  */
  void setOpen();
  void setClosed();
  void setOpening();
  void setClosing();

  /**
   * Metodo que devuelve si la gate esta abierta del todo
  */
  bool isOpen();

  /**
   * Metodo que devuelve si la gate esta cerrada del todo
  */
  bool isClosed();

private:
  Rect dest_world;
  Sprite *sprite;
  bool is_open = false;
  bool is_closed = true;
  int code;
  std::unordered_map<int, Sprite *> states;
};

#endif
