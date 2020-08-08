#ifndef PUZZLEGAME_H
#define PUZZLEGAME_H

#include <iostream>
#include <curses.h>
#include <stdlib.h>  
#include <time.h>  
#include "Point2D.h"

using namespace std;

class PuzzleGame {
private:
    char matrix[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
    Point2D points[9] = { Point2D(6, 8), Point2D(6, 15), Point2D(6, 22), Point2D(11, 8), Point2D(11, 15), Point2D(11, 22), Point2D(16, 8), Point2D(16, 15), Point2D(16, 22) };
    char choice;
    int indexChoice;
    int index0;
   

    void layout();
    void randomize();
    void drawBoard();
    int findElement(char num);
    void getChoice();
    bool checkChoice();
    void swap();
    bool checkWin();
public:
    PuzzleGame();
    void playGame();

};

#endif