//완료된 실습 - 추상클래스 + 유일객체 Game
#include "Game.h"

int main(int argc, char* argv[])
{
  int yes = 0; //재미로 만든... yes변수
  cout << "게임을 실행하시겠습니까 : "; //게임 실행문
  cin >> yes; //게임 실행 yes입력
  if(yes == 1)
  {
	  if(TheGame::Instance()->init("GFW - HW", 100, 100, 640, 480, 0))
    {
	    while (TheGame::Instance()->running())
	    {
		    TheGame::Instance()->handleEvents();
		    TheGame::Instance()->update();
		    TheGame::Instance()->render();
        SDL_Delay(10);
	    }
    }
    else
    {
      cout << "게임이 정상적으로 실행되지 않았습니다." << SDL_GetError() << endl;
      return -1;
    }
  }
  else
  {
    cout << "게임이 꺼졌습니다" << endl;
    TheGame::Instance()->~Game();
    TheGame::Instance()->clean();
  }
  TheGame::Instance()->clean();
	return 0;
}