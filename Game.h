#ifndef __Game__
#define __Game__
#include "App.h"
#include <SDL.h>
#include <time.h>
#include "Board.h"

class Game{
public:
    enum State{STATE_RUNNING,STATE_STOPPED};

    Game();
    ~Game();

    void update(SDL_Event* event);
    void render();
    void checkwin();

     const int SCREEN_BOARD=300;

private:
    State state;
    Board board;
    bool xIsNext;
    void resetGame();



};
#endif // __Game__
