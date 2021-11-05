#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{
  handleInput();
  m_currentFrame = ( (SDL_GetTicks() / 100) % 7);
  SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput()
{
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) 
  { m_velocity.setX(2); m_currentRow = 3; }

  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
  { m_velocity.setX(-2); m_currentRow = 2; }

  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) 
  { m_velocity.setY(-2); m_currentRow = 1; }
  
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) 
  { m_velocity.setY(2); m_currentRow = 0; }
}