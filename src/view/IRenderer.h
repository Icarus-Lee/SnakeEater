#ifndef IRENDERER_H
#define IRENDERER_H

#include "../model/Map.h"
#include "../model/Snake.h"
#include "../model/Food.h"

class IRenderer {
 protected:
  IRenderer() = default;

 public:
  virtual void Render(Map& map, Snake& snake, Food& food) = 0;
  virtual ~IRenderer()                                    = default;
};

#endif