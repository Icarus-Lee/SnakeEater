#ifndef TUI_RENDERER_H
#define TUI_RENDERER_H

#include "IRenderer.h"
#include <string>

class TUIRenderer : public IRenderer {
 private:
  std::string buffer_;
  char        main_char_;
  char        border_char_;
  char        food_char_;
  char        snake_char_;
  void        RenderMap(Map& map);
  void        RenderSnake(Snake& snake, Map& map);
  void        RenderFood(Food& food, Map& map);

 public:
  TUIRenderer(char main_char, char border_char, char food_char,
              char snake_char);
  void Render(Map& map, Snake& snake, Food& food) override;
};

#endif