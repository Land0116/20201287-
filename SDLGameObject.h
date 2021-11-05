#ifndef SDLGameObject_H
#define SDLGameObject_H

#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"

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

    Vector2D m_posion;
    Vector2D m_velocity; //속도
    Vector2D m_acceleration; //가속도
};

#endif