#include "./controller/GameController.h"
#include "./view/TUIRenderer.h"

int main() {
  GameController game_controller(
      200, 20, 10, std::make_unique<TUIRenderer>('.', '#', '*', 'O'));
  game_controller.Tick();
  return 0;
}