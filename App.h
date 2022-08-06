#ifndef __App__
#define __App__
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <memory>
class Game;

class App{
public:
    App();
    ~App();
     const int SCREEN_WIDTH=640;
     const int SCREEN_HEIGHT=480;


      bool init();
      void run();

      static SDL_Renderer* getRenderer() {return m_Renderer;}
      static SDL_Window* getWindow()  {return m_Window;}

private:
    std::unique_ptr<Game> game;
    static SDL_Renderer* m_Renderer;
    static SDL_Window* m_Window;
    SDL_Event event;

};
#endif // __App__
