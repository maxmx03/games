#pragma once
#include <array>
#include <functional>
#include <raylib.h>

struct Command {
  int key;
  std::function<void(Vector2 &, float)> action;
};
using InputConfig = const std::array<Command, 4>;

class Controller {
  private:
    float speed = 100.0f;

  public:
    void playerUp(Vector2 &player, float dt);
    void playerRight(Vector2 &player, float dt);
    void playerDown(Vector2 &player, float dt);
    void playerLeft(Vector2 &player, float dt);
    auto getConfig() -> InputConfig;
};
