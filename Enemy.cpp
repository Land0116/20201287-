#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
  SDLGameObject::draw();
}

void Enemy::update()
{
  m_currentFrame = ( (SDL_GetTicks() / 100) % 6);
  m_acceleration.setX(1);
  m_acceleration.setY(1);
  SDLGameObject::update();
}

void Enemy::clean() {}