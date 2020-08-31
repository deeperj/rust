#pragma once
#include <iostream>
#include <curses.h>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

const int BSZ = 3;
const int BSZ2 = BSZ * BSZ;

class PuzzleGame {
protected:
    bool winner=false;
    int choice=-1,id0=-1,idc=-1;
    bool choiceValid();
    void drawBoard();
    void randomizeBoard();
    bool checkWin();
    int getChoice();
    int find(int);
public:
    friend class Test;
    int board[BSZ2] = {1,4,2,
                       6,0,5,
                       7,3,8};
    PuzzleGame();
    void swapPiece();
    void startGame();
};

class BoardPiece {
private:
    int number;
    int poscode;
public:
    BoardPiece() {};
    BoardPiece(int,int);
    void setVal(int);
    void render();
};

class Board :public PuzzleGame{
    BoardPiece pieces[];
public:
    Board();
    void startGame();
    void render();
    void swapPiece();
};
