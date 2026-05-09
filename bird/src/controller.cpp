#include "controller.hpp"
#include <raylib.h>

auto Controller::getConfig() -> InputConfig {
  auto up = [&](Vector2 &player, float dt) -> void { player.y -= speed * dt; };
  auto right = [&](Vector2 &player, float dt) -> void { player.x += speed * dt; };
  auto down = [&](Vector2 &player, float dt) -> void { player.y += speed * dt; };
  auto left = [&](Vector2 &player, float dt) -> void { player.x -= speed * dt; };
  InputConfig inputConfig = {{
    {.key=KEY_W, .action=up},
    {.key=KEY_S, .action=down},
    {.key=KEY_A, .action=left},
    {.key=KEY_D, .action=right},
  }};
  return inputConfig;
}
