#pragma once
#include <iostream>
#include <string>
#include <curses.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

const int BSZ = 3;
const int BSZ2 = BSZ * BSZ;

class Point2D {
public:
	int mx, my;
	Point2D() {}
	Point2D(int x, int y) :mx(x), my(y){}
};

class BoardSquare {
private:
    int number;
    int poscode;
    Point2D bpos;
public:
	BoardSquare(){}
	BoardSquare(Point2D bp, int v, int p);
	void setVal(int);
	int val();
	void render();
};

class Board{
private:
	Point2D startpos;
public:
	BoardSquare squares[BSZ2];
	Board(Point2D start);
	void render();// :call displayBoard();
    void swapPiece();
};

class PuzzleGame{
  private:
    Board board;
    int input;
    void randomizeBoard();
    //getInputFromUser();  //cin  //getch
    void checkInput();
    void gameEnding();

  public:
    void startGame();
    const int find(const int haystack[], int needle, int size);
};