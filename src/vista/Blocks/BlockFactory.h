#ifndef __BLOCKFACTORY_H__
#define __BLOCKFACTORY_H__
#include <string>
#include "../Sprite.h"
#include "Stone_block.h"
#include "Metal_block.h"
#include "Shoot_block.h"
#include "Triangle_block.h"

class BlockFactory
{
public:
  static Block *createBlock(const Window &window, const int &code)
  {
    if (code == 1)
    {
      return new MetalBlock(window);
    }
    else if (code == 2)
    {
      return new StoneBlock(window);
    }
    else if (code == 3)
    {
      return new ShootBlock(window);
    }
    else if (code >= 4)
    {
        std::cout<<"code:              "<<code<<std::endl;
      return new TriangleBlock(window,code%4);
    }
    return nullptr;
  }
};

#endif