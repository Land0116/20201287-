// #include "GameObject.h"

// void GameObject::load(int x, int y, int width, int height, string textureID)
// {
//   m_x = x;
//   m_y = y;
//   m_width = width;
//   m_height = height;
//   m_textureID = textureID;
//   m_currentFrame = 0;
//   m_currentRow = 0;
// }

// void GameObject::draw(SDL_Renderer* pRenderer)
// {
//   TheTextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
// }

// void GameObject::update()
// {
//   m_x += 1;
// }

// void GameObject::clean() {}