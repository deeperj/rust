#include "CW.h"

void puzzle::SetupBoard(char caaBoard[3][3]) {

	for (int iRow = 0; iRow < 3; ++iRow) {
		for (int iCol = 0; iCol < 3; ++iCol) {
			caaBoard[iRow][iCol] = kcaaInitial[iRow][iCol];
		}
	}
}

void puzzle::PrintBoard(char caaBoard[3][3]) {
	for (int iRow = 0; iRow < 3; iRow++) {
		for (int iCol = 0; iCol < 3; iCol++)
			cout << "  " << caaBoard[iRow][iCol];
		cout << endl << endl;
	}
		
	
}

void puzzle::EmptyBox(int& irRow, int& irCol, char caaBoard[3][3]) {
	for (int iRow = 0; iRow < 3; ++iRow) {
		for (int iCol = 0; iCol < 3; ++iCol) {
			if (caaBoard[iRow][iCol] == ' ') {
				irRow = iRow;
				irCol = iCol;
			}
		}
	}
}

void puzzle::Randomize(char caaBoard[3][3]) {
	srand((unsigned int)time(0));
	for (int iIndex = 0; iIndex < 1000000; ++iIndex) {
		const int kiNextMove = (rand() % 4);
		switch (kiNextMove) {
		case 0:
		{
			Move(caaBoard, keUp);
			break;
		}
		case 1:
		{
			Move(caaBoard, keDown);
			break;
		}
		case 2:
		{
			Move(caaBoard, keLeft);
			break;
		}
		case 3:
		{
			Move(caaBoard, keRight);
			break;
		}
		}
	}
}

int puzzle::checkwin(char caaBoard[3][3]) {
	EmptyBox(iRowSpace, iColSpace, caaBoard);
	int solved = 1;
	for (int iRow = 0; iRow < 3; iRow++) {
		for (int iCol = 0; iCol < 3; iCol++) {
			if (caaBoard[iRow][iCol] != bcaaInitial[iRow][iCol])
				solved = 0;
		}

	}
	return solved;
}

void puzzle::Move(char caaBoard[3][3], const EMove keMove) {
	EmptyBox(iRowSpace, iColSpace, caaBoard);
	int iRowMove(iRowSpace);
	int iColMove(iColSpace);
	switch (keMove) {
	case keUp:
	{
		iRowMove = iRowSpace + 1;
		break;
	}
	case keDown:
	{
		iRowMove = iRowSpace - 1;
		break;
	}
	case keLeft:
	{
		iColMove = iColSpace + 1;
		break;
	}
	case keRight:
	{
		iColMove = iColSpace - 1;
		break;
	}
	}

	if (iRowMove >= 0 && iRowMove < 3 && iColMove >= 0 && iColMove < 3) {
		caaBoard[iRowSpace][iColSpace] = caaBoard[iRowMove][iColMove];
		caaBoard[iRowMove][iColMove] = ' ';
	}
}