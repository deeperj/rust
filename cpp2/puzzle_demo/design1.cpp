// design1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "PuzzleGame.hpp"

using std::cout;
using std::endl;

int main() {
	//int main1(int argc, char **argv) {
	// initialise
	// setup memory and clear screen
	initscr();
	
	PuzzleGame start;
	getch();

	//deallocate memory and ends ncurses
	endwin();

	return 0;
}

