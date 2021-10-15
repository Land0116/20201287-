#ifndef Player_H
#define Player_H

#include "GameObject.h"

class Player : public GameObject
{
  public :
    Player() {}
    ~Player() {}
    
    void load(int x, int y, int width, int height, string textureID);
    
    void draw(SDL_Renderer* pRenderer);
    void update();

    void clean();
};

#endif