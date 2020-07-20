// design1.cpp : Defines the entry point for the console application.
//

#include "PuzzleGame.hpp"
#include <iostream>
#include <curses.h>

using std::cout;
using std::endl;

int main() {
	// initialise
	// setup memory and clear screen
	initscr();

	PuzzleGame start;

	getch();

	//deallocate memory and ends ncurses
	endwin();

	return 0;
}

