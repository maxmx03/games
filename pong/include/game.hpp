#pragma once
#include "controller.hpp"
#include <raylib.h>

const int paddleWidth = 15;
const int paddleHeight = 80;
const int ballSize = 12;

class Game {
private:
  Rectangle player;
  Rectangle enemy;
  Rectangle ball;
  Vector2 ballDir;
  Controller controller;
  int playerScore;
  int enemyScore;
  const float ballSpeed = 400.f;

public:
  void update(float dt);
  void draw();
  void resetBall();
  void handlePaddleCollision(const Rectangle &paddle);
  Game();
};
