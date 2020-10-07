#include<iostream>
#include<ctime>
#include"Puzzle.h"
using namespace std;


//------------------------------------------------------------
// unit_tests()
// do the unit testing, call unit tests

void unit_tests() {
	Puzzle game;
	cout << "Testing the functions: \n";
	game.testAllFunctions();
}


//------------------------------------------------------------
// main()
// create Puzzle object, play the turn until user has won

int main()
{
	srand(unsigned int(time(0)));		// to generate random numbers

	// To Unit tests, uncomment to run these
	//void unit_tests();
	


	Puzzle game; int moves = 1;
	cout << "Welcome to Puzzle game\n";
	
	game.turn();
	while (!(game.isWon()))
	{
		//system("clear");	// for linux to clear screen
		system("cls"); //for windows to clear screen
		game.turn();
		moves++;
		
	}
	game.show();
	cout << "Congratulations You Solved Puzzle in " << moves << " moves" << endl;

}