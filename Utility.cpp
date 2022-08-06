#include "Utility.h"
#include <SDL.h>
#include "App.h"
#include <iostream>
#include <math.h>

void Utility::drawX(int r,int c)
{
    //int width=80;
    //int height=80;

     //draw X
     SDL_SetRenderDrawColor(App::getRenderer(),0,0,255,255);
     SDL_RenderDrawLine(App::getRenderer(),(190+c*100),(110+r*100),(150+c*100+100),(70+r*100+100));// \//


      SDL_SetRenderDrawColor(App::getRenderer(),0,0,255,255);
    SDL_RenderDrawLine(App::getRenderer(),(190+c*100),(70+r*100+100),(150+c*100+100),(110+r*100));// \//

}

/*void Utility::drawO(int r,int c)
{
    //draw square
     SDL_Rect rect={(190+c*100),(110+r*100),60,60};

     SDL_SetRenderDrawColor(App::getRenderer(),255,0,0,255);
     SDL_RenderDrawRect(App::getRenderer(),&rect);
}
*/

void Utility::drawO(int r,int c)
{


    int point1=std::abs((150+c*100+100)-(190+c*100));
    int point2=std::abs((70+r*100+100)-(110+r*100));
    int centerX =(190+c*100)+30;
    int centerY = (110+r*100)+30;

    int radious = 30;

    double step = 2*M_PI/30;
    int endX = centerX + radious;
    int endY = centerY;

     SDL_SetRenderDrawColor(App::getRenderer(),255,0,0,255);
    for(double angle=0; angle<2*M_PI; angle+=step)
    {
        int startX = endX;
        int startY = endY;
        endX = radious * std::cos(angle) + centerX;
        endY = radious * std::sin(angle) + centerY;
        SDL_RenderDrawLine(App::getRenderer(), startX, startY, endX, endY);
    }
}





void Utility::drawXWinner()
{
    // X on left
     SDL_SetRenderDrawColor(App::getRenderer(),0,0,255,255);
     SDL_RenderDrawLine(App::getRenderer(),30,200,130,300);

    SDL_SetRenderDrawColor(App::getRenderer(),0,0,255,255);
    SDL_RenderDrawLine(App::getRenderer(),30,300,130,200);

    // X on right
     SDL_SetRenderDrawColor(App::getRenderer(),0,0,255,255);
     SDL_RenderDrawLine(App::getRenderer(),500,200,600,300);

    SDL_SetRenderDrawColor(App::getRenderer(),0,0,255,255);
    SDL_RenderDrawLine(App::getRenderer(),500,300,600,200);

}

void Utility::drawOWinner()
{
     int centerX =80;
    int centerY = 250;

    int radious = 30;

    double step = 2*M_PI/30;
    int endX = centerX + radious;
    int endY = centerY;

     SDL_SetRenderDrawColor(App::getRenderer(),255,0,0,255);
    for(double angle=0; angle<2*M_PI; angle+=step)
    {
        int startX = endX;
        int startY = endY;
        endX = radious * std::cos(angle) + centerX;
        endY = radious * std::sin(angle) + centerY;
        SDL_RenderDrawLine(App::getRenderer(), startX, startY, endX, endY);
    }

     centerX =550;
     centerY = 250;

     radious = 30;

     step = 2*M_PI/30;
     endX = centerX + radious;
     endY = centerY;

     SDL_SetRenderDrawColor(App::getRenderer(),255,0,0,255);
    for(double angle=0; angle<2*M_PI; angle+=step)
    {
        int startX = endX;
        int startY = endY;
        endX = radious * std::cos(angle) + centerX;
        endY = radious * std::sin(angle) + centerY;
        SDL_RenderDrawLine(App::getRenderer(), startX, startY, endX, endY);
    }
}

void Utility::drawEqual()
{
    SDL_SetRenderDrawColor(App::getRenderer(),0,0,0,255);
    //*_* on left
    SDL_RenderDrawLine(App::getRenderer(),30,300,130,300);

    SDL_Rect rectl={30,250,20,20};// pos left eye

     SDL_RenderDrawRect(App::getRenderer(),&rectl);

      rectl.x=110; //pos right eye
      rectl.y=250;
     SDL_RenderFillRect(App::getRenderer(),&rectl);



     //*_* on right
     SDL_RenderDrawLine(App::getRenderer(),500,300,600,300);
     SDL_Rect rectr={500,250,20,20};//pos left eye

     SDL_RenderDrawRect(App::getRenderer(),&rectr);

      rectr.x=580;//pos right eye
      rectr.y=250;
     SDL_RenderFillRect(App::getRenderer(),&rectr);




}

