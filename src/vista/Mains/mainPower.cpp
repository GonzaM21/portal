#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "../Window.h"
#include "../PowerBall/PowerBall.h"
#include "../Constants.h"

int main(int argc, char **argv)
{
  try
  {
    Window window(800, 600);
    PowerBall powerBall(window);
    Rect dest(150, 150, 110, 50);
    int x = 150, y = 150;
    for (size_t i = 0; i < 100; i++)
    {
      window.fill();
      // powerBall.render(dest);
      if (powerBall.hitted())
      {
        x += 20;
        dest.set(x, y, 110, 50);
      }
      if (x >= 500)
      {
        dest.set(x, y, 110, 50);
        powerBall.setHitting();
        if (powerBall.isDone())
        {
          break;
        }
      }
      window.render();
      SDL_Delay(100);
    }
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}