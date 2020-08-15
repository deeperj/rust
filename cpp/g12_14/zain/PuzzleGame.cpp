#include "PuzzleGame.h"

void PuzzleGame::Initialize(char fixarr[3][3]) {
	
const char useBoard[3][3] = {
	    {'1', '2', '3',},
			{'4', '5', '6',},
			{'7', '8', ' ' }
			
	};		
for (int J = 0; J < 3; ++J) {
for (int K = 0; K < 3; ++K) {
fixarr[J][K] = useBoard[J][K];
}
}
}

void PuzzleGame::DrawBoard(char fixarr[3][3]) {
	using namespace std;
	for (int J = 0; J < 3; ++J) {
		for (int K = 0; K < 3; ++K) {
			cout << fixarr[J][K];
		}
		cout << endl;
	}
}
void PuzzleGame::Randomize(char fixarr[3][3]) {
	using namespace std;
	srand((unsigned int)time(0));
	for (int iIndex = 0; iIndex < 1000; ++iIndex) {
		const int kiNextMove = (rand() % 4);
		switch (kiNextMove) {
		case 0:
		{
			Move(fixarr, moveUp);
			break;
		}
		case 1:
		{
			Move(fixarr, moveDown);
			break;
		}
		case 2:
		{
			Move(fixarr, moveLeft);
			break;
		}
		case 3:
		{
			Move(fixarr, moveRight);
			break;
		}
		}
	}
}

void PuzzleGame::Checkspace(int& Row, int& Col, char fixarr[3][3]) {
for (int J = 0; J < 3; ++J) {
for (int K = 0; K < 3; ++K) {
if (fixarr[J][K] == ' ') {
Row = J;
Col = K;
}
}
}
}


void PuzzleGame::Move(char fixarr[3][3], const button kbutton) {
	int JFREE;
	int KFREE;
	Checkspace(JFREE, KFREE, fixarr);
	int Jchange(JFREE);
	int Kchange(KFREE);
	switch (kbutton) {
	case moveUp:
	{
		Jchange = JFREE + 1;
		break;
	}
	case moveDown:
	{
		Jchange = JFREE - 1;
		break;
	}
	case moveLeft:
	{
		Kchange = KFREE + 1;
		break;
	}
	case moveRight:
	{
		Kchange = KFREE - 1;
		break;
	}
	}

	if (Jchange >= 0 && Jchange < 3 && Kchange >= 0 && Kchange < 3) {
		fixarr[JFREE][KFREE] = fixarr[Jchange][Kchange];
		fixarr[Jchange][Kchange] = ' ';
	}
}
 int PuzzleGame::checkwin(char fixarr[3][3]){
   char fixboardb[3][3] = {
	    {'1', '2','3',},
			{'4', '5','6',},
			{'7', '8',' ' }
		};		
  int check = 1;
  using namespace std;
  for (int JRow = 0; JRow < 3; JRow++) {
	for (int KCol = 0; KCol < 3; KCol++){
	if (fixarr[JRow][KCol] != fixboardb[JRow][KCol])
  check = 0;
  }
	}
  return check;
  }


	