#ifndef Enemy_H
#define Enemy_H

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
  public :
    Enemy(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    ~Enemy() {}
};

#endif