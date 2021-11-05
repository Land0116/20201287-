#ifndef Game_H
#define Game_H

#include <iostream>
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include <vector>

using namespace std;


enum pMove
{
  Down = 0,
  Up,
  Left,
  Right
};

class Game
{
public:
  static Game* Instance()
  {
    if(s_pInstance == 0)
    {
      s_pInstance = new Game();
      return s_pInstance;
    }
    return s_pInstance;
  }
	~Game() {}
  
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

  void quit() { m_bRunning = false; }

  SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
  Game() { m_AposX = 0; m_AposY = 0; m_Aflip = SDL_FLIP_NONE;}
  static Game* s_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	/*SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;*/
  SDL_Event event;
  

	bool m_bRunning;
  bool m_iAnimalmove;

  // int m_currentFrame;
  SDL_RendererFlip m_Aflip;
  int m_AposX;
  int m_AposY;

  vector<GameObject*> m_gameObjects;

};
typedef Game TheGame;

#endif