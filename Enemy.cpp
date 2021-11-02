#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
  SDLGameObject::draw();
}

void Enemy::update()
{
  m_posion.setX(m_posion.getX() + 1);
  m_posion.setY(m_posion.getY() + 1);
  m_currentFrame = ( (SDL_GetTicks() / 100) % 6);
}

void Enemy::clean() {}