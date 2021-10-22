#ifndef LoaderParams_H
#define LoaderParams_H

#include "SDL.h"
#include "GameObject.h"
#include "TextureManager.h"

using namespace std;

class LoaderParams
{
  public :
    LoaderParams(int x, int y, int width, int height, string textureID) : 
    m_x(x), 
    m_y(y), 
    m_width(width),
    m_height(height),
    m_textureID(textureID) {}

    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    string getTextureID() const { return m_textureID; }

    private : 
    int m_x, m_y;
    int m_width, m_height;
    string m_textureID;
};

#endif