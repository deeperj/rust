#include "CW.h"

int main() {
	puzzle L;
  char cNextMove;
	char caaBoard[3][3];
	L.SetupBoard(caaBoard);
	L.Randomize(caaBoard);
	do {
		L.PrintBoard(caaBoard);
		cout << endl << "w = Up, d = Right, a = Left, s = Down" << endl;
		cin >> cNextMove;
		EMove eNextMove = (EMove)cNextMove;
		L.Move(caaBoard, eNextMove);
		//cout << "out here";     //  check sequence  for debugging 
		cout << endl;
		if (L.checkwin(caaBoard) == 1) {
			L.PrintBoard(caaBoard);
			cout << "Solved. Written By Muhammad Kaleem !" << endl;
			return 0;
		}
	system("clear"); // use system("cls")  for visual studios as clear is used for linux
	} while (true);
}

