#ifndef PUZZLEGAME_H
#define PUZZLEGAME_H

#include <iostream>
#include <ctime>
#include<string>

using std::cout;
using std::cin;
using std::endl;

const int BSZ=3;
const int BSZ2=BSZ*BSZ;

class Puzzlegame{

int choice,idv,id0,find;
bool winner, choicecorrect;

private:
bool checkChoice();
void randomizeboard();
void swapPiece();
void checkwin();
void getchoice();
void displayBoard();
void displaywinner();

public:
void startgame();
int board[BSZ2]={0,1,2,3,4,5,6,7,8};

};

#endif
