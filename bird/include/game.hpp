#pragma once
#include "player.hpp"
#include <raylib.h>

const int screenWidth = 1280;
const int screenHeight = 720;
const int paddleWidth = 15;
const int paddleHeight = 80;

class Game {
  private:
    Texture2D background;
    Texture2D playerTexture;
    Player player;

  public:
    void update(float dt);
    void draw();
    void clean();
    Game();
};
