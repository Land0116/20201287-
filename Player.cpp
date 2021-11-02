#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{
  m_posion.setX(m_posion.getX() - 1);
  //m_posion.setY(m_posion.getY() + 1);
  m_currentFrame = ( (SDL_GetTicks() / 100) % 7);
}

void Player::clean() {}