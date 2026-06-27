#include "TUIRenderer.h"
#include "../utils/ConsoleClear.h"
#include "../utils/ConsoleColour.h"
#include <iostream>

TUIRenderer::TUIRenderer(char main_char, char border_char, char food_char,
                         char snake_char)
    : buffer_(""),
      main_char_(main_char),
      border_char_(border_char),
      food_char_(food_char),
      snake_char_(snake_char) {
  buffer_.reserve(4096);
}

bool IsSnakeBody(int x, int y, const Snake& snake) {
  const auto& positions = snake.GetPositions();
  for (const auto& pos : positions) {
    if (pos.x == x && pos.y == y)
      return true;
  }
  return false;
}

void TUIRenderer::Render(Map& map, Snake& snake, Food& food) {
  ClearConsole();
  buffer_.clear();
  int       width     = map.GetWidth();
  int       height    = map.GetHeight();
  PointType food_pos  = food.GetPosition();

  buffer_            += ConsoleColour::RED;
  for (int j = 0; j < width + 2; ++j) {
    buffer_ += border_char_;
  }
  buffer_ += ConsoleColour::RESET;
  buffer_ += '\n';

  for (int y = 0; y < height; ++y) {
    buffer_ += ConsoleColour::RED;
    buffer_ += border_char_;
    buffer_ += ConsoleColour::RESET;

    for (int x = 0; x < width; ++x) {
      if (!food.IfEaten() && food_pos.x == y && food_pos.y == x) {
        buffer_ += ConsoleColour::YELLOW;
        buffer_ += food_char_;
        buffer_ += ConsoleColour::RESET;
      } else if (IsSnakeBody(y, x, snake)) {
        buffer_ += ConsoleColour::GREEN;
        buffer_ += snake_char_;
        buffer_ += ConsoleColour::RESET;
      } else {
        buffer_ += main_char_;
      }
    }

    buffer_ += ConsoleColour::RED;
    buffer_ += border_char_;
    buffer_ += ConsoleColour::RESET;
    buffer_ += '\n';
  }

  buffer_ += ConsoleColour::RED;
  for (int j = 0; j < width + 2; ++j) {
    buffer_ += border_char_;
  }
  buffer_ += ConsoleColour::RESET;
  buffer_ += '\n';

  std::cout << buffer_;
}