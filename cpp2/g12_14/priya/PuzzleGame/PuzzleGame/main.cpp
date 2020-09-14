#include<iostream>
#include<ctime>
#include"puzzle.h"
using namespace std;

int main()
{
	srand(unsigned int(time(0)));		// to generate random numbers
	puzzle p1; int moves = 1;
	cout << "\n\n\n\t Welcome to Puzzle game\n";
	p1.turn();
	while (!(p1.isWon()))
	{
		//system("clear");	// for linux to clear screen
		system("cls"); //for windows to clear screen
		p1.turn();
		moves++;
		
	}
	p1.show();
	cout << "Congratulations You Solved puzzle in " << moves << " moves" << endl;

}