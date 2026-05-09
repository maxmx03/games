#include "game.hpp"
#include "player.hpp"
#include <raymath.h>

Game::Game() : player(Vector2{.x=400, .y=200}, 100, 100) {
  Image bgImg = LoadImage("sprites/background.png");
  ImageResize(&bgImg, screenWidth, screenHeight);
  Texture2D background = LoadTextureFromImage(bgImg);
  this->background = background;
  UnloadImage(bgImg);
}

void Game::update(float dt) {
  player.update(dt);
}

void Game::draw() {
  DrawTexture(background, 0, 0, WHITE);
  player.draw();
}

void Game::clean() {
  UnloadTexture(background);
  player.clean();
}
