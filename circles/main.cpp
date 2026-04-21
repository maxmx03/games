#include <algorithm>
#include <array>
#include <random>
#include <raylib.h>
#include <raymath.h>

const int screenWidth = 700;
const int screenHeight = 400;

template <typename T> T getRandom(T min, T max);

class Ball {
private:
  Vector2 pos = {.x = (float)screenWidth / 2, .y = (float)screenHeight / 2};
  int radius = 20;
  Vector2 speed;
  Color color;

public:
  Ball() {
    float vel = 10.f;
    Vector2 speed = {getRandom(-vel, vel), getRandom(-vel, vel)};
    color = {
        static_cast<unsigned char>(getRandom(0, 255)),
        static_cast<unsigned char>(getRandom(0, 255)),
        static_cast<unsigned char>(getRandom(0, 255)),
        static_cast<unsigned char>(getRandom(100, 255)),
    };
    this->speed = speed;
  };
  void draw() const { DrawCircle(pos.x, pos.y, radius, color); }
  void move() {
    pos.x += speed.x;
    pos.y += speed.y;
    if ((pos.x - radius) <= 0 || (pos.x + radius) >= screenWidth)
      speed.x *= -1.0f;
    if ((pos.y + radius) >= screenHeight || (pos.y - radius) <= 0)
      speed.y *= -1.0f;
  }
};

int main() {
  InitWindow(screenWidth, screenHeight, "balls");
  SetTargetFPS(60);
  Ball ball;
  std::array<Ball, 10> balls;
  std::generate(balls.begin(), balls.end(), []() { return Ball(); });

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    for (auto &ball : balls) {
      ball.draw();
      ball.move();
    }
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

template <typename T> T getRandom(T min, T max) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<float> distr(min, max);
  return distr(gen);
}
