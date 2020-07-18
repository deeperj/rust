// design1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <curses.h>

using std::cout;
using std::endl;

int main() {
	// initialise
	// setup memory and clear screen
	initscr();

	

	getch();

	//deallocate memory and ends ncurses
	endwin();

	return 0;
}

