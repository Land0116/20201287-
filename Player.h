#ifndef Player_H
#define Player_H

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
  public :
    Player(const LoaderParams* pParams);
    
    //void load(int x, int y, int width, int height, string textureID);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    ~Player() {}
};

#endif