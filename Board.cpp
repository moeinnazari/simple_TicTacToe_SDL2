#include "Board.h"
#include <iostream>
#include "App.h"
#include "Utility.h"

Board::Board()
{
    restart();
}

void Board::render()
{
    SDL_SetRenderDrawColor(App::getRenderer(),255,255,255,255);
    renderBoard();
    renderPieces();
}

void Board::restart()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            matrix[i][j]=EMPTY;

    numberOfCell=0;
}


bool Board::isCellEmpty(int r,int c)
{
    if(r>=0 && r<3 && c>=0 && c<3)
       return matrix[r][c]==EMPTY;

    return false;
}

void Board::drawCell(int r,int c,bool xIsNext)
{
    if(r>=0 && r<3 && c>=0 && c<3 && numberOfCell<9)
        matrix[r][c]=(xIsNext) ? X:O;

    numberOfCell++;

}

bool Board::isFull()
{
    return numberOfCell==9;
}

bool Board::checkwin()
{
    return (checkCols() || checkRows() || checkDiagonals());
}

bool Board::checkCols()
{
    if(matrix[0][0]==matrix[1][0] && matrix[1][0]==matrix[2][0] && !isCellEmpty(2,0))
    {
        return true;
    }
    if(matrix[0][1]==matrix[1][1] && matrix[1][1]==matrix[2][1] && !isCellEmpty(2,1))
    {
        return true;
    }
    if(matrix[0][2]==matrix[1][2] && matrix[1][2]==matrix[2][2] && !isCellEmpty(2,2))
    {
        return true;
    }

}

bool Board::checkRows()
{
    if(matrix[0][0]==matrix[0][1] && matrix[0][1]==matrix[0][2] && !isCellEmpty(0,2))
    {
        return true;
    }
    if(matrix[1][0]==matrix[1][1] && matrix[1][1]==matrix[1][2] && !isCellEmpty(1,2))
    {
        return true;
    }
    if(matrix[2][0]==matrix[2][1] && matrix[2][1]==matrix[2][2] && !isCellEmpty(2,2))
    {
        return true;
    }


}

bool Board::checkDiagonals()
{
    if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] && !isCellEmpty(2,2))
    {
        return true;
    }
    if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0] && !isCellEmpty(2,0))
    {
        return true;
    }


}


void Board::renderBoard()
{
    //top
    SDL_SetRenderDrawColor(App::getRenderer(),255,255,255,255);
    SDL_RenderDrawLine(App::getRenderer(),170,90,470,90);

    //bottom
    SDL_SetRenderDrawColor(App::getRenderer(),255,255,255,255);
    SDL_RenderDrawLine(App::getRenderer(),170,390,470,390);

    //left
    SDL_SetRenderDrawColor(App::getRenderer(),255,255,255,255);
    SDL_RenderDrawLine(App::getRenderer(),170,90,170,390);

    //right
    SDL_SetRenderDrawColor(App::getRenderer(),255,255,255,255);
    SDL_RenderDrawLine(App::getRenderer(),470,90,470,390);

    //2 line vertical center
    SDL_SetRenderDrawColor(App::getRenderer(),255,255,255,255);
    SDL_RenderDrawLine(App::getRenderer(),270,90,270,390);

    SDL_SetRenderDrawColor(App::getRenderer(),255,255,255,255);
    SDL_RenderDrawLine(App::getRenderer(),370,90,370,390);

    //2 line horizontal
    SDL_SetRenderDrawColor(App::getRenderer(),255,255,255,255);
    SDL_RenderDrawLine(App::getRenderer(),170,190,470,190);

    SDL_SetRenderDrawColor(App::getRenderer(),255,255,255,255);
    SDL_RenderDrawLine(App::getRenderer(),170,290,470,290);




}
void Board::renderPieces()
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            switch(matrix[i][j]){
            case X:
                Utility::drawX(i,j);
                break;
            case O:
               Utility::drawO(i,j);
                break;
            }
        }
    }


}



