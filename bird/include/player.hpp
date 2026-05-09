#pragma once
#include "controller.hpp"

class Player {
  private:
    Vector2 position;
    Controller controller;
    Texture2D texture;
    float width;
    float height;

  public:
    void update(float dt);
    void draw();
    void clean();
    Player(Vector2 position, float width, float height);
};
