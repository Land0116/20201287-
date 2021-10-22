#include "Game.h"
#include "Player.h"
#include "Enemy.h"

enum pMove PlayerMove;

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
    cout << "생성" << endl;
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
      {
				SDL_SetRenderDrawColor(m_pRenderer, 255, 100, 100, 0);
        
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
  m_gameObjects.push_back( new Player( new LoaderParams(100,100, 150, 120, "player") ) );
  m_gameObjects.push_back( new Enemy( new LoaderParams(100,100, 128, 82, "animate") ) );
	m_bRunning = true;

	return true;
}

void Game::update()
{
  for(int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
  
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
  
  for(int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
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