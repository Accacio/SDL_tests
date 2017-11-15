#include "game.h"
#include <SDL2/SDL_image.h>


bool Game::init(const char* title,int xpos,int ypos,int height,int width,int flags)
{

  // initialize SDL
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
      // if succeeded create our window
      m_pWindow = SDL_CreateWindow(title,xpos,ypos,height,width,flags);
      // if the window creation succeeded create our renderer
      if(m_pWindow != 0)
	{

	  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

	  if (m_pRenderer!=0) 
	    {
	      std::cout << "renderer creation success\n";

	      SDL_Surface* pTempSurface=IMG_Load("../assets/airplane.png");
	      m_pTexture=SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	      SDL_FreeSurface(pTempSurface);

	      SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);


	      m_destinationRectangle.x=m_sourceRectangle.x=0;
	      m_destinationRectangle.y=m_sourceRectangle.y=0;
	      m_destinationRectangle.w=m_sourceRectangle.w;
	      m_destinationRectangle.h=m_sourceRectangle.h;

	      
	      SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

	      
	    }
	  else
	    {
	      std::cout << "renderer init fail\n";
	      return false;
	    }
	}
      else
	{
	  std::cout << "window init fail\n";
	  return false;
	} 
    }
  else
    {
      std::cout << "window init fail\n";
      return false; // sdl could not initialize
    }
  std::cout << "init success\n";
  m_bRunning=true;
  return true; 
}


void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
  SDL_RenderPresent(m_pRenderer);
}


void Game::clean()
{
  std::cout <<"cleaning game\n";
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}

void Game::handleEvents()
{
  SDL_Event event;

  if (SDL_PollEvent(&event)) 
    {
      switch (event.type) {
      case SDL_QUIT:
	m_bRunning=false;
	
	break;
	
      default:
	break;
      }
    }
}
