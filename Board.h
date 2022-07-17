#ifndef __Board__
#define __Board__

class Board{
public:
    enum Piece{EMPTY,X,O};
    Board();
    ~Board();
    void render();
    void restart();

    bool isCellEmpty(int r,int c);
    void drawCell(int r,int c,bool xIsNext=true);
    bool isFull();
    bool checkwin();


    void message(bool xIsNext);

private:
    Piece matrix[3][3];
     void renderBoard();
    void renderPieces();

    bool checkCols();
    bool checkRows();
    bool checkDiagonals();

    int numberOfCell;

};
#endif // __Board__
