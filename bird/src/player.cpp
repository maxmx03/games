#include "player.hpp"
#include "controller.hpp"

Player::Player(Vector2 position, float width, float height) {
  Controller controller;
  this->controller = controller;
  Image playerImg = LoadImage("sprites/parrot.png");
  ImageResize(&playerImg, width, height);
  Texture2D playerTexture = LoadTextureFromImage(playerImg);
  this->texture = playerTexture;
  this->position = position;
  UnloadImage(playerImg);
}

void Player::update(float dt) {
  for (const auto &config : controller.getConfig()) {
    if (IsKeyDown(config.key)) {
      config.action(position, dt);
    }
  }
}

void Player::draw() {
  DrawTexture(texture, position.x, position.y, WHITE);
}

void Player::clean() {
  UnloadTexture(texture);
}
