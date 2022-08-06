#include "App.h"
#include <iostream>

SDL_Renderer* App::m_Renderer=0;
SDL_Window* App::m_Window=0;

App::App()
{
  game=std::unique_ptr<Game>(new Game());
}

App::~App()
{

    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    m_Renderer=0;
    m_Window=0;

    IMG_Quit();
    SDL_Quit();
}

bool App::init()
{
     bool success=true;
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        std::cout<<"initialize SDL failed\n"<<SDL_GetError()<<"\n";
        success=false;
    }
    else
    {
        m_Window=SDL_CreateWindow("tic tac toe",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(m_Window==NULL)
        {
            std::cout<<"creation window failed\n"<<SDL_GetError()<<"\n";
            success=false;
        }
        else
        {
            m_Renderer=SDL_CreateRenderer(m_Window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(m_Renderer==NULL)
            {
                std::cout<<"creation renderer failed\n"<<SDL_GetError()<<"\n";
                success=false;
            }
            else{
                int flag=IMG_INIT_PNG;
                if(!(IMG_Init(flag) & flag))
                {
                    std::cout<<"IMG INIT failed\n";
                    success=false;
                }
                else
                {
                    SDL_SetRenderDrawColor(m_Renderer,0,255,255,255);
                }
            }
        }
    }
    return success;
}

void App::run()
{
    bool isRunning=true;
    while(isRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT || event.key.keysym.sym==SDLK_ESCAPE)
            {
                isRunning=false;
            }
             game->update(&event);
        }


       game->render();
       game->checkwin();
    }
}

