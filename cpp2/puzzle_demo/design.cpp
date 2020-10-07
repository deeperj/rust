// main.cpp : Defines the entry point for the console application.
//

#include "PuzzleGame.hpp"

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

