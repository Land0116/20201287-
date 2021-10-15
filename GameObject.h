#ifndef GameObject_H
#define GameObject_H

#include "SDL.h"
#include "TextureManager.h"

using namespace std;

class GameObject
{
  public :
    GameObject() {}
    ~GameObject() {}
    
    void load(int x, int y, int width, int height, string textureID);
    
    void draw(SDL_Renderer* pRenderer);
    void update();

    void clean();

  protected :
    string m_textureID;

    int m_x;
    int m_y;
    int m_width;
    int m_height;

    int m_currentFrame;
    int m_currentRow;
};

#endif