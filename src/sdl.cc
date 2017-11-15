#include <iostream>
#include "game.h"


bool g_bRunning=false;



int main(int argc, char* args[])
{
  Game *game = new Game();
  game->init("Chapter 1: Setting up SDL",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		 640, 480,SDL_WINDOW_SHOWN); 

  while (game->running())
    {
      game->handleEvents();
      game->update();
      game->render();
    }
  game->clean();
  return 0;
}


