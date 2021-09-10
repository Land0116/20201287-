#include <iostream>
#include <string.h>
#include <SDL.h>
using namespace std;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int changeColor = 0; //랜덤색깔
int startNum = 0;

string gamestart;
//보기 쉽게 const를 사용하였습니다
const int Red_r = 255;
const int Green_g = 255;
const int Blue_b = 255;

bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(title, xpos,
			ypos, height, width, flags);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}

	else
	{
		return false;
  }

	return true;
}
//입력받기
void Input()
{
  cout << "색깔을 변경하려면 yes를 입력 -> ";
  while(true)
  {
    cin >> gamestart;
    if(gamestart == "yes")
    {
      startNum = 1;
      break;
    }
    else if(gamestart == "No")
    {
      startNum = 0;
      break;
    }
    else
    {
      cout << "다시 입력해주세요. -> ";
    }
  }
}

//업데이트
void Update() //랜덤 색깔변경!
{
  if(startNum == 1)
  {
	  SDL_SetRenderDrawColor(g_pRenderer, (rand() % Red_r) ,(rand() % Green_g), (rand() % Blue_b), 0);
    changeColor++;
  }
  else if(startNum == 0)
  {
    cout << "색깔이 랜덤하게 변경되지 않았습니다." << endl;
  }
  else
  {
    startNum = 0;
  }
}
//렌더러
void render()
{
  if(startNum == 1)
  {
	  SDL_RenderClear(g_pRenderer);
	  SDL_RenderPresent(g_pRenderer);
  }
  
  if(changeColor >= 5) //5번 색깔변환 후 g_bRunning을  false로 만들어 게임루프를 멈춘다.
  {
    g_bRunning = false;
  }
}

int main(int arge, char* args[])
{
    if (init("HelloSDL_RandomColor", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 720, 480, SDL_WINDOW_SHOWN))//720x480화면
	  {
		  g_bRunning = true;

	  }
	  else
	  {
		  return 1;
	  }

	  while (g_bRunning)
	  {
      Input();
      Update();//추가한 코드입니다!
      SDL_Delay(2000);
		  render();
	  }

  SDL_Delay(2000); //랜덤색깔 변환 후 2초뒤 윈도우창 삭제
	SDL_Quit();

	return 0;

}

/*if (init("HelloSDL", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN))//실습1*/
      //SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
  /*SDL_SetRenderDrawColor(g_pRenderer, 0 ,0 , Blue_b, 0);//실습2
  SDL_Delay(2000);
  SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);*/