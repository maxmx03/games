#include "game.hpp"
#include <raylib.h>
#include <raymath.h>

const int screenWidth = 1280;
const int screenHeight = 720;

Game::Game() {
  InitWindow(screenWidth, screenHeight, "Pong game");
  Controller controller;
  this->controller = controller;

  player = {20, (screenHeight - paddleHeight) / 2.0f, (float)paddleWidth,
            (float)paddleHeight};
  enemy = {screenWidth - 20.f - paddleWidth,
           (screenHeight - paddleHeight) / 2.0f, (float)paddleWidth,
           (float)paddleHeight};

  playerScore = 0;
  enemyScore = 0;
  resetBall();
}

void Game::resetBall() {
  ball = {(screenWidth - ballSize) / 2.0f, (screenHeight - ballSize) / 2.0f,
          (float)ballSize, (float)ballSize};

  float randomY = (GetRandomValue(-100, 100) / 100.f);
  if (std::fabs(randomY) < 0.2f) {
    randomY = 0.5f;
  }

  ballDir = {1.f, randomY};
  float length = std::sqrt(ballDir.x * ballDir.x + ballDir.y * ballDir.y);
  ballDir.x /= length;
  ballDir.y /= length;
}

void Game::handlePaddleCollision(const Rectangle &paddle) {
  float paddleCenterY = paddle.y + paddle.height / 2.f;
  float ballCenterY = ball.y + ball.height / 2.f;
  float relativeIntersect =
      (paddleCenterY - ballCenterY) / (paddle.height / 2.f);
  float bounceAngle = relativeIntersect * (PI / 4.f);
  float direction = (paddle.x < screenWidth / 2.f) ? 1.f : -1.f;

  ballDir.x = direction * std::cos(bounceAngle);
  ballDir.y = -std::sin(bounceAngle);
}

void Game::draw() {
  BeginDrawing();
  ClearBackground(BLACK);

  for (int i = 0; i < screenHeight; i += 20) {
    DrawRectangle(screenWidth / 2 - 2, i, 4, 10, GRAY);
  }

  DrawRectangleRec(player, WHITE);
  DrawRectangleRec(enemy, WHITE);
  DrawRectangleRec(ball, WHITE);

  DrawText(TextFormat("%d", playerScore), screenWidth / 4, 20, 40, WHITE);
  DrawText(TextFormat("%d", enemyScore), screenWidth * 3 / 4, 20, 40, WHITE);

  EndDrawing();
}

void Game::update(float dt) {
  for (const auto &config : controller.getConfig()) {
    if (IsKeyDown(config.key)) {
      config.action(player.y, enemy.y);
    }
  }

  player.y = Clamp(player.y, 0, screenHeight - paddleHeight);
  enemy.y = Clamp(enemy.y, 0, screenHeight - paddleHeight);

  ball.x += ballDir.x * ballSpeed * dt;
  ball.y += ballDir.y * ballSpeed * dt;

  if (ball.y <= 0 || ball.y + ballSize >= screenHeight)
    ballDir.y *= -1;

  if (CheckCollisionRecs(player, ball))
    handlePaddleCollision(player);
  if (CheckCollisionRecs(enemy, ball))
    handlePaddleCollision(enemy);

  if (ball.x < -ballSize) {
    enemyScore++;
    resetBall();
  }
  if (ball.x > screenWidth) {
    playerScore++;
    resetBall();
  }
}
