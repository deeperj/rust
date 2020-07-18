#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

const int BSZ = 3;
const int BSZ2 = BSZ * BSZ;

class PuzzleGame {
private:
	int id0 = -1, idv = -1;
	int choice;
	bool winner = false;
	void drawBoard();
	void randomizeBoard();
	bool choiceOK();
	int getChoice();
	bool checkWinner();
	int swap();
	void startGame();
	int find(int);
public:
	int board[BSZ2] = { 1, 4, 2, 6, 0, 5, 7, 3, 8 };
	PuzzleGame();
};


class PuzzlePiece {
private:
	int number;
	int poscode;
public:
	PuzzlePiece(){};
	PuzzlePiece(int v, int p);
	int val();
	int pos();

};

class PuzzleBoard {
private:
public:
	PuzzlePiece pieces[BSZ2];
	PuzzleBoard();
};