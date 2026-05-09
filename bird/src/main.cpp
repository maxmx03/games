#include "game.hpp"

auto main() -> int {
  InitWindow(screenWidth, screenHeight, "Bird");
  Game game;
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    game.update(dt);
    BeginDrawing();
    ClearBackground(BLACK);
    game.draw();
    EndDrawing();
  }
  game.clean();
  CloseWindow();
  return 0;
}
