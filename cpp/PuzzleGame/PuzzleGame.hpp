#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

const int BSZ = 3;
const int BSZ2 = BSZ * BSZ;

class PuzzleGame {
private:
    bool winner;
    int choice,id0=-1,idc=-1;
    bool choiceValid();
    void swapPiece();
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
    void startGame();
};