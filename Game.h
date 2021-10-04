#ifndef Game_H
#define Game_H

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

class Game
{
public:
	Game() { m_AposX = 100; m_AposY = 100; m_Aflip = SDL_FLIP_NONE;}
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	/*SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;*/
  SDL_Event event;

  TextureManager m_textureManager;

	bool m_bRunning;
  bool m_iAnimalmove;

  int m_currentFrame;
  SDL_RendererFlip m_Aflip;
  int m_AposX;
  int m_AposY;

};

#endif