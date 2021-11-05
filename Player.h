#ifndef Player_H
#define Player_H

#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
  public :
    Player(const LoaderParams* pParams);
    
    //void load(int x, int y, int width, int height, string textureID);
    
    void handleInput();
    virtual void draw();
    virtual void update();
    virtual void clean();
    ~Player() {}
};

#endif