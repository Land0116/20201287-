#ifndef SDLGameObject_H
#define SDLGameObject_H

#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"

using namespace std;

class SDLGameObject : public GameObject
{
  public :
    SDLGameObject(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual ~SDLGameObject() {}

  protected : 
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    int m_currentRow;
    int m_currentFrame;
    string m_textureID;
};

#endif