#ifndef ___Game___
#define ___Game___

#include<SDL2/SDL.h>
#include <iostream>
#include "SDL2/SDL_image.h"

class Game
{
public:
  Game(){};
  ~Game(){}

  bool init(const char* title,int xpos,int ypos,int height,int width,int flags);

  void render();

  void update(){};

  void handleEvents();

  void clean();

  bool running(){return m_bRunning;}

private:
  bool m_bRunning;

  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;

  SDL_Texture* m_pTexture;
  SDL_Rect m_sourceRectangle;
  SDL_Rect m_destinationRectangle;

};





#endif
