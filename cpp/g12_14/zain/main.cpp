#include "PuzzleGame.h"
using namespace std;


int main()
  {
  PuzzleGame P;
  char fixarr[3][3];
	P.Initialize(fixarr);
	P.Randomize(fixarr);
  cout << "\t\t\t  WELCOME  TO THE PUZZLE GAME "<<endl;
  cout << "\t\t\t\t  By Muhammad Zain    "<<endl;
  cout<< "instructions :  W KEY IS USED TO MOVE THE NUMBERS UP " << endl;
	cout << " \t\t\t    S KEY IS USED TO MOVE THE NUMBERS DOWN " << endl;
	cout <<  "\t\t\t    A KEY IS USED TO MOVE THE NUMBERS LEFT " << endl;
	cout <<  "\t\t\t    D KEY IS USED TO MOVE THE NUMBERS RIGHT " << endl;
cout << "Please move the numbers to start the game : "<<endl;

	do 
  {
    P.DrawBoard(fixarr);
    char Choice;
    cout << "Enter  Number  : "<< endl;
		cin >> Choice;
    button eNextMove = (button)Choice;
		P.Move(fixarr, eNextMove);
		cout << endl;
    if (P.checkwin(fixarr) == 1) {
    P.DrawBoard(fixarr);
    cout << endl << "\t\t WE HAVE A WINNER " << endl;
      cout << endl << "\t\t Congratulations  " << endl;
    return 0;
  }
	} 
  while (true);
  }

