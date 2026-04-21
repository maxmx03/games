#include <array>
#include <functional>
#include <raylib.h>
#include <raymath.h>

const int screenWidth = 800;
const int screenHeight = 600;

class PlayerController {
public:
  void Up(Vector2 &v) { v.y -= speed; }
  void Down(Vector2 &v) { v.y += speed; }
  void Left(Vector2 &v) { v.x -= speed; }
  void Right(Vector2 &v) { v.x += speed; }

private:
  float speed = 5.0f;
};

struct Command {
  int key;
  std::function<void(Vector2 &)> action;
};

int main() {
  InitWindow(screenWidth, screenHeight, "C++ Raylib");
  Vector2 playerPos = {screenWidth / 2.0f, screenHeight / 2.0f};
  Vector2 enemyPos = {screenWidth / 3.0f, screenHeight / 3.0f};
  float enemySpeed = 2.0f;
  PlayerController controller;
  const std::array<Command, 4> inputConfig = {
      {{KEY_W, [&](Vector2 &v) { controller.Up(v); }},
       {KEY_S, [&](Vector2 &v) { controller.Down(v); }},
       {KEY_A, [&](Vector2 &v) { controller.Left(v); }},
       {KEY_D, [&](Vector2 &v) { controller.Right(v); }}}};
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    for (const auto &config : inputConfig) {
      if (IsKeyDown(config.key)) {
        config.action(playerPos);
      }
    }

    enemyPos = Vector2MoveTowards(enemyPos, playerPos, enemySpeed);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Use WASD to move", 10, 10, 20, GRAY);
    DrawCircleV(playerPos, 25, YELLOW);
    DrawCircleV(enemyPos, 25, BLUE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
