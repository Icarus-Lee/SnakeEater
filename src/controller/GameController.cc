#include "GameController.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <time.h>

GameController::GameController(int tick_ms, int width, int height,
                               std::unique_ptr<IRenderer> renderer)
    : if_stop_(false),
      tick_ms_(tick_ms),
      renderer_(std::move(renderer)),
      snake_(PointType{0, 0}, Direction::RIGHT),
      map_(width, height),
      food_() {
  food_.Yield({height / 2, width / 2});
  srand(static_cast<unsigned int>(time(nullptr)));
}

bool GameController::IfEatenFood() const {
  return snake_.GetPositions().front().x == food_.GetPosition().x &&
         snake_.GetPositions().front().y == food_.GetPosition().y;
}

bool GameController::YieldFood() {
  if (IfEatenFood()) {
    food_.Disappear();
    return true;
  }
  return false;
}

void GameController::Tick() {
  char input;
  while (!if_stop_) {
    renderer_->Render(map_, snake_, food_);
    if (_kbhit()) {
      input = _getch();
      switch (input) {
      case 'w': snake_.ChangeDirection(Direction::UP); break;
      case 's': snake_.ChangeDirection(Direction::DOWN); break;
      case 'a': snake_.ChangeDirection(Direction::LEFT); break;
      case 'd': snake_.ChangeDirection(Direction::RIGHT); break;
      case 'q': if_stop_ = true; break;
      }
    }
    if (IfEatenFood()) {
      snake_.Grow();
      food_.Disappear();
    } else {
      snake_.Move();
    }
    if (map_.IsOutOfMap(snake_.GetPositions().front())) {
      std::cout << "Game Over!" << std::endl;
      if_stop_ = true;
    }
    if (food_.IfEaten()) {
      food_.Yield({rand() % map_.GetHeight(), rand() % map_.GetWidth()});
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(tick_ms_));
  }
}