#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
  SDLGameObject::draw();
  m_currentRow = 3;
}

void Player::update()
{
  m_currentFrame = ( (SDL_GetTicks() / 100) % 7);
  m_velocity.setX(1);
  SDLGameObject::update();
}

void Player::clean() {}