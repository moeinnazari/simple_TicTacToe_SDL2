#include "Utility.h"
#include <SDL.h>
#include "App.h"
#include <iostream>

void Utility::drawX(int r,int c)
{
    int width=80;
    int height=80;

     //draw X
     SDL_SetRenderDrawColor(App::getRenderer(),0,0,255,255);
     SDL_RenderDrawLine(App::getRenderer(),(190+c*100),(110+r*100),(150+c*100+100),(70+r*100+100));// \//


      SDL_SetRenderDrawColor(App::getRenderer(),0,0,255,255);
    SDL_RenderDrawLine(App::getRenderer(),(190+c*100),(70+r*100+100),(150+c*100+100),(110+r*100));// \//

}

void Utility::drawO(int r,int c)
{
    //draw square
     SDL_Rect rect={(190+c*100),(110+r*100),60,60};

     SDL_SetRenderDrawColor(App::getRenderer(),255,0,0,255);
     SDL_RenderDrawRect(App::getRenderer(),&rect);
}

