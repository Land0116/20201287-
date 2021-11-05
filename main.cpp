//완료된 실습 - 키 입력
#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
  Uint32 frameStart, frameTime;
  
	if(TheGame::Instance()->init("GFW - HW", 100, 100, 640, 480, 0))
  {
	  while (TheGame::Instance()->running())
	  {
      frameStart = SDL_GetTicks();
		  TheGame::Instance()->handleEvents();
		  TheGame::Instance()->update();
		  TheGame::Instance()->render();
      frameTime = SDL_GetTicks() - frameStart;

      if(frameTime < DELAY_TIME) { SDL_Delay((int)(DELAY_TIME - frameTime)); }
	  }
  }
  TheGame::Instance()->clean();
	return 0;
}