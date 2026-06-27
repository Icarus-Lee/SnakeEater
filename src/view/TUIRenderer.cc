#include "TUIRenderer.h"
#include <iostream>

TUIRenderer::TUIRenderer(char main_char, char border_char, char food_char,
                         char snake_char)
    : buffer_(""),
      main_char_(main_char),
      border_char_(border_char),
      food_char_(food_char),
      snake_char_(snake_char) {}

void TUIRenderer::RenderMap(Map& map) {
  for (int j = 0; j <= map.GetWidth() + 1; ++j) {
    buffer_ += border_char_;
  }
  buffer_ += '\n';
  for (int i = 0; i < map.GetHeight(); ++i) {
    buffer_ += border_char_;
    for (int j = 0; j < map.GetWidth(); ++j) {
      buffer_ += main_char_;
    }
    buffer_ += border_char_;
    buffer_ += '\n';
  }
  for (int j = 0; j <= map.GetWidth() + 1; ++j) {
    buffer_ += border_char_;
  }
}

void TUIRenderer::RenderSnake(Snake& snake, Map& map) {
  std::deque<PointType> positions = snake.GetPositions();
  for (auto& pos : positions) {
    buffer_[(pos.x + 1) * (map.GetWidth() + 3) + pos.y + 1] = snake_char_;
  }
}

void TUIRenderer::RenderFood(Food& food, Map& map) {
  if (!food.IfEaten()) {
    PointType pos = food.GetPosition();
    buffer_[(pos.x + 1) * (map.GetWidth() + 3) + pos.y + 1] = food_char_;
  }
}

void TUIRenderer::Render(Map& map, Snake& snake, Food& food) {
  std::cout << "\033[2J\033[1;1H";  // Clear the console
  buffer_ = "";
  RenderMap(map);
  RenderSnake(snake, map);
  RenderFood(food, map);
  std::cout << buffer_ << std::endl;
}