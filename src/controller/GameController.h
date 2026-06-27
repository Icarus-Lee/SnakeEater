#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <memory>
#include "../model/Map.h"
#include "../model/Snake.h"
#include "../model/Food.h"
#include "../view/IRenderer.h"

class GameController {
 private:
  bool                       if_stop_;
  int                        tick_ms_;
  std::unique_ptr<IRenderer> renderer_;
  Snake                      snake_;
  Map                        map_;
  Food                       food_;

 public:
  GameController(int tick_ms, int width, int height,
                 std::unique_ptr<IRenderer> renderer);
  bool IfEatenFood() const;
  bool YieldFood();
  void Tick();
};

#endif