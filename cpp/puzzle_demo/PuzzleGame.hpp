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
	void startGame();
	int find(int);
public:
	int board[BSZ2] = { 1, 4, 2, 6, 0, 5, 7, 3, 8 };
	PuzzleGame();
};