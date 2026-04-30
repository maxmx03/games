#include "controller.hpp"
#include <raylib.h>

void Controller::playerUp(float &py, float &ey) { py -= speed; }
void Controller::playerDown(float &py, float &ey) { py += speed; }
void Controller::enemyUp(float &py, float &ey) { ey -= speed; }
void Controller::enemyDown(float &py, float &ey) { ey += speed; }

InputConfig Controller::getConfig() {
  InputConfig inputConfig = {
      {{KEY_W, [&](float &py, float &ey) { playerUp(py, ey); }},
       {KEY_S, [&](float &py, float &ey) { playerDown(py, ey); }},
       {KEY_UP, [&](float &py, float &ey) { enemyUp(py, ey); }},
       {KEY_DOWN, [&](float &py, float &ey) { enemyDown(py, ey); }}}};
  return inputConfig;
}
