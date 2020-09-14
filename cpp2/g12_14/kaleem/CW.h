#include <iostream>
#include <cstdlib>
#include <ctime>


using std::time;
using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;


enum EMove {
	keUp = 'w',
	keDown = 's',
	keLeft = 'a',
	keRight = 'd'
};


class puzzle {
private:

	char cNextMove;
	char caaBoard[3][3];
	int iRowSpace;
	int iColSpace;
	int correct;
	int kcaaInitial[3][3] = {
	  {'1','2','3',},
	  {'4','5','6',},
	  {'7','8',' ' }

	};
	int bcaaInitial[3][3] = {
	  {'1', '2','3',},
	  {'4', '5','6',},
	  {'7', '8',' ' }

	};
	
public:
	int checkwin(char[3][3]);
	void Randomize(char[3][3]);
	void PrintBoard(char[3][3]);
	void EmptyBox(int&, int&, char[3][3]);
	void Move(char[3][3], const EMove);	
	void SetupBoard(char[3][3]);
};