#include "vista/EventsHandler.h"
#include "vista/Player/Player.h"
#include "vista/Blocks/Metal_block.h"
#include "vista/Blocks/Stone_block.h"
#include "vista/Blocks/Shoot_block.h"
#include "vista/Blocks/BlockFactory.h"
#include "vista/Gate/Gate.h"

EventsHandler::EventsHandler(Model &model) : model(model)
{
}

void EventsHandler::handle()
{
  bool running = true;
  int x = 0;
  Rect dest(1, 0, 1, 2);
  model.setGate(dest, 1, 3);
  Rect dest2(-3, 0, 0.5, 0.5);
  model.setBlock(dest2, 1);
  Rect dest3(-2.5, 0, 0.5, 0.5);
  model.setBlock(dest3, 1);
  Rect dest4(-2, 0, 0.5, 0.5);
  model.setBlock(dest4, 1);
  Rect dest5(-1.5, 0, 0.5, 0.5);
  model.setBlock(dest5, 1);
  Rect dest6(-1, 0, 0.5, 0.5);
  model.setBlock(dest6, 1);
  Rect dest10(-0.5, 0, 0.5, 0.5);
  model.setBlock(dest10, 1);
  Rect dest11(0, 0, 0.5, 0.5);
  model.setBlock(dest11, 1);
  Rect dest12(0.5, 0, 0.5, 0.5);
  model.setBlock(dest12, 1);
  Rect dest13(1, 0, 0.5, 0.5);
  model.setBlock(dest13, 1);
  Rect dest14(1.5, 0, 0.5, 0.5);
  model.setBlock(dest14, 1);
  Rect dest7(1.5, -0.30, 1, 0.25);
  model.setAcid(dest7);
  Rect dest8(3.5, -0.30, 1, 0.25);
  model.setPortal(dest8, 0, 1, 1, 1);
  model.setPortal(dest8, 1, 2, 2, 1);
  Rect dest9(0, -1.1, 0.5, 1.6);
  model.setPlayer(dest9, 1, 0, 1);
  model.setPlayerId(1);
  while (running)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {

      switch (event.type)
      {
      case SDL_KEYDOWN:
      {
        SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &)event;
        switch (keyEvent.keysym.sym)
        {
        case SDLK_RIGHT:
        {
          
          break;
        }
        case SDLK_LEFT:
        {
          std::cout << "Izquierda" << std::endl;
          break;
        }
        case SDLK_UP:
        {
          std::cout << "Arriba" << std::endl;
          model.setGate(dest, 1, 0);
          break;
        }
        case SDLK_DOWN:
        {
          std::cout << "ABAJO" << std::endl;
          // model.setPlayer(dest9, 1, 1, 1);
          model.setGate(dest, 1, 2);
          break;
        }
        case SDLK_F11:
          std::cout << "fullscreen" << std::endl;
          model.fullscreen();
          break;
        }
      }
      break;
      case SDL_QUIT:
      {
        std::cout << "cerrando" << std::endl;
        running = false;
        break;
      }
      // case SDL_MOUSEMOTION:
      // {
      // 	SDL_MouseMotionEvent &mouseEvent = (SDL_MouseMotionEvent &)event;
      // 	int x;
      // 	int y;
      // 	SDL_GetMouseState(&x,
      // 										&y);
      // 	std::cout << "x " << x << "y " << y << std::endl;
      // 	break;
      // 	switch (mouseEvent.type)
      // 	{

      // 	default:
      // 		break;
      // 	}
      // }
      case SDL_MOUSEBUTTONDOWN:
      {
        SDL_MouseButtonEvent &mouseEvent = (SDL_MouseButtonEvent &)event;
        int x;
        int y;
        SDL_GetMouseState(&x,
                          &y);
        std::cout << "clicked"
                  << "x " << x << "y " << y << std::endl;

        break;
      }
      }
    }
    model.renderAll();
    SDL_Delay(80);
  }
}

EventsHandler::~EventsHandler()
{
}