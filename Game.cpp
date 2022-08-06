#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include "Board.h"

Game::Game()
{
    srand(time(0));
    resetGame();
}

void Game::render()
{
    SDL_SetRenderDrawColor(App::getRenderer(),0,255,0,255);
    SDL_RenderClear(App::getRenderer());
    board.render();

    if(state==STATE_STOPPED)
    {
        board.message(xIsNext);
    }
    SDL_RenderPresent(App::getRenderer());

}

void Game::update(SDL_Event* event)
{

    if(state==STATE_STOPPED)
    {
        SDL_Delay(1500);
        resetGame();

        board.restart();
        return;
    }

    if(event->type==SDL_MOUSEBUTTONDOWN)
    {

        int x,y;

        SDL_GetMouseState(&x,&y);

        int row=(y>90 && y<390) ? ((y-90)/(SCREEN_BOARD/3)):-1;
        int col=(x>170 && x<470) ? ((x-170)/(SCREEN_BOARD/3)):-1;
        if(row!=-1 && col!=-1){

           if(board.drawCell(row,col,xIsNext))
           {
           // std::cout<<"x:\t"<<x<<"\ny:\t"<<y<<"\n";
           // std::cout<<"row\t"<<row<<"\ncol\t"<<col<<"\n";
            xIsNext=!xIsNext;
           }

        }
    }

}


void Game::checkwin()
{
    if(board.checkwin())
    {
        state=STATE_STOPPED;


        //std::cout<<"game is finish";
    }
    else if(board.isFull())
    {
        state=STATE_STOPPED;
    }
}


void Game::resetGame()
{

    xIsNext=rand()& 1?true:false;

    state=STATE_RUNNING;

}

Game::~Game()
{

}




