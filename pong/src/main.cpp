#include "game.hpp"
#include <raylib.h>
#include <raymath.h>

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
