#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class PuzzleGame {
private:
    void checkChoice();
    void swapPiece();
    void drawBoard();
    void randomizeBoard();
    bool checkWin();
    void getChoice();
public:
    int board[];
    PuzzleGame();
    void startGame();
};