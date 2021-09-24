#include "Game.h"
#include "SDL_image.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
  //SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
  //[ 4주차 실습 - 애니메이션 스프라이트 ]
  //SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/animate.bmp");
  //[ 4주차 실습 - SDL_image]
  //SDL_Surface* pTempSurface = IMG_Load("Assets/animate.png");
  SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 0);
        //[ 3주차 실습 (예외처리하기) ]
        if(pTempSurface != 0)
        {
          m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
          SDL_FreeSurface(pTempSurface);
          //SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
          //[ 4주차 실습 - 애니메이션 스프라이트 ]
          m_sourceRectangle.w = 128;
          m_sourceRectangle.h = 82;
          m_sourceRectangle.x = 0;
          m_sourceRectangle.y = 0;

        /*[4주차 응용 실습 - 1]
          m_destinationRectangle.w = m_sourceRectangle.w = 50;
          m_destinationRectangle.h = m_sourceRectangle.h = 50;

          [ 4주차 응용 실습 - 2]
          m_destinationRectangle.w = m_sourceRectangle.w = 50;
          m_destinationRectangle.h = m_sourceRectangle.h = 50;

          m_destinationRectangle.x = 170;            m_destinationRectangle.y = 130;
          [ 4주차 응용 실습 - 3]
          m_sourceRectangle.x = 51;
          m_sourceRectangle.y = 50;

          m_destinationRectangle.w = m_sourceRectangle.w = 50;
          m_destinationRectangle.h = m_sourceRectangle.h = 50;

          m_destinationRectangle.x = 160;
          m_destinationRectangle.y = 130;

          [ 4주차 응용 실습 - 4]
          m_destinationRectangle.w = m_sourceRectangle.w = 480;
          m_destinationRectangle.h = m_sourceRectangle.h = 640;

          m_destinationRectangle.x = 0;
          m_destinationRectangle.y = 0;*/


          m_destinationRectangle.w = m_sourceRectangle.w;
          m_destinationRectangle.h = m_sourceRectangle.h;

          m_destinationRectangle.x = 0;
          m_destinationRectangle.y = 0;


          /*m_destinationRectangle.x = m_sourceRectangle.x = 0;
          m_destinationRectangle.y = m_sourceRectangle.y = 0;*/

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
	}
	else
	{
		return false;
	}

  m_iAnimalmove = false;
	m_bRunning = true;
  m_FlipConut = 0;
  m_Flip_num = 0;
	return true;
}

void Game::update()
{
  //[ 4주차 실습 - 애니메이션 스프라이트 / 심화 이동시 애니메이션 재생]
  if(m_iAnimalmove == true)
  {
    m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 6);
    m_iAnimalmove = false;
  }
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
  //[ 4주차 실습 심화 (이미지 회전))]
  switch (m_FlipConut)
  {
  case 0:
  case 1:
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    break;
  case 2:
    SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
    break;
  case 3:
    SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, -90, 0, SDL_FLIP_VERTICAL);
    break;
  case 4:
    SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 90, 0, SDL_FLIP_VERTICAL);
    break;
  }

	SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
	return m_bRunning;
}

void Game::handleEvents()
{
	if (SDL_PollEvent(&event))
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
          if(m_destinationRectangle.y != 0)
          {
            m_destinationRectangle.y -= 10;
            m_iAnimalmove = true;
            m_FlipConut = 3;
            break;
          }
          else
          {
            m_destinationRectangle.y = 0;
            break;
          }
        }
        case SDLK_s:
        {
          if(m_destinationRectangle.y != 290)
          {
            m_destinationRectangle.y += 10;
            m_iAnimalmove = true;
            m_FlipConut = 4;
            break;
          }
          else
          {
            m_destinationRectangle.y = 290;
            break;
          }
        }
        case SDLK_a:
        {
          if(m_destinationRectangle.x != 0)
          {
            m_destinationRectangle.x -= 10;
            m_iAnimalmove = true;
            m_FlipConut = 2;
            break;
          }
          else
          {
            m_destinationRectangle.x = 0;
            break;
          }
        }
        case SDLK_d:
        {
          if(m_iAnimalmove == false)
          {
            if(m_destinationRectangle.x != 360)
            {
              m_destinationRectangle.x += 10;
              m_iAnimalmove = true;
              m_FlipConut = 1;
              break;
            }
            else
            {
              m_destinationRectangle.x = 360;
              break;
            }
          }
        }
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