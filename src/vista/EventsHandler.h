#ifndef __EVENTSHANDLER_H__
#define __EVENTSHANDLER_H__
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Rect.h"
#include "Sprite.h"
#include "Camara.h"
#include "Model.h"

class EventsHandler
{
public:
  /**
     * Crea una EventsHandler
     **/
  EventsHandler(Model &model);
  /**
     * Libera la memoria reservada por la EventsHandler
     **/
  ~EventsHandler();

  void handle();

private:
  SDL_Event event;
  Model model;
};

#endif
