// PuzzleGame.hpp : Defines the entry point for the console application.
//

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

class PuzzleBoard;

class PuzzleGame {
public:
private:
	int choice;
	void drawBoard();
	void randomizeBoard();
	bool choiceOK();
	int getChoice();
	bool checkWinner();
	void startGame();
	void startUI();
	int find(int);
	bool winner = false;
public:
	int id0 = -1, idv = -1;
	int swap();
	PuzzleBoard *brd;
	int board[BSZ2] = { 1, 4, 2, 6, 0, 5, 7, 3, 8 };
	PuzzleGame();
	~PuzzleGame();
};

class PuzzlePiece {
private:
	int number;
	int poscode;
public:
	PuzzleBoard* brd;
	PuzzlePiece(){};
	PuzzlePiece(PuzzleBoard* b,int v, int p);
	void render();
	void setVal(int);

};
class PuzzleBoard{
private:
public:
	Point2D startpos;
	PuzzleGame *puzzle;
	PuzzlePiece pieces[BSZ2];
	PuzzleBoard(PuzzleGame *g);
	int swap();
	void render();
};
