#include <iostream>
#include "Game.h"

enum pMove PlayerMove;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
  GameObject* m_go = new GameObject();
  Player* m_player = new Player();

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
      {
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 0);
        
        if(!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
        {
          return false;
        }
        if(!TheTextureManager::Instance()->load("Assets/pngwing.png", "player", m_pRenderer))
        {
          return false;
        }
      }
			else
      {
				return false;
      }
        
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

  m_iAnimalmove = false;
	m_bRunning = true;

  m_go->load(100, 100, 128, 82, "animate");
  m_player->load(300, 300, 150, 120, "player");
  m_gameObjects.push_back(m_go);
  m_gameObjects.push_back(m_player);
	return true;
}

void Game::update()
{
  for(int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
  //[ 4주차 실습 - 애니메이션 스프라이트 / 심화 이동시 애니메이션 재생]
  if(m_iAnimalmove == true)
  {
    m_currentFrame = ( (SDL_GetTicks() / 100) % 7);
  }
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
  
  for(int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw(m_pRenderer);
  }

	SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
	return m_bRunning;
}

void Game::handleEvents()
{
	if (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		  case SDL_QUIT:
			  m_bRunning = false;
			  break;
        // [ 3주차 실습 심화]
      case SDL_KEYDOWN:
      {
		    switch (event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            clean();
            m_bRunning = false;
            break;
          case SDLK_w:
          {
            if(m_AposY != 0)
            {
              m_AposY -= 10;
              PlayerMove = Up;
              m_iAnimalmove = true;
              break;
            }
            else
            {
              m_AposY = 0;
              break;
            }
          }
          case SDLK_s:
          {
            if(m_AposY != 250)
            {
              m_AposY += 10;
              PlayerMove = Down;
              m_iAnimalmove = true;
              break;
            }
            else
            {
              m_AposY = 250;
              break;
            }
          }
          case SDLK_a:
          {
            if(m_AposX != 0)
            {
              m_AposX -= 10;
             PlayerMove = Left;
              m_iAnimalmove = true;
              break;
            }
            else
            {
              m_AposX = 0;
              break;
            }
          }
          case SDLK_d:
          {
            if(m_AposX != 360)
            {
              m_AposX += 10;
              PlayerMove = Right;
              m_iAnimalmove = true;
              break;
            }
            else
            {
              m_AposX = 360;
              break;
            }
          }
        }
        break;
      }
      case SDL_KEYUP:
      {
		    switch (event.key.keysym.sym)
        {
          case SDLK_w:
          case SDLK_s:
          case SDLK_a:
          case SDLK_d:
            m_iAnimalmove = false;
            break;
        }
      }
      default:
		    break;
    }
	}
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}