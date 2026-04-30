#pragma once
#include <array>
#include <functional>

struct Command {
  int key;
  std::function<void(float &, float &)> action;
};
using InputConfig = const std::array<Command, 4>;

class Controller {
private:
  float speed = 5.0f;

public:
  void playerUp(float &py, float &ey);
  void playerDown(float &py, float &ey);
  void enemyUp(float &py, float &ey);
  void enemyDown(float &py, float &ey);
  InputConfig getConfig();
};
