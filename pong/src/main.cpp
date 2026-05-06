#include "game.hpp"

int main() {
  Game game;
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    game.update(dt);
    game.draw();
  }
  CloseWindow();
  return 0;
}
