#include "PuzzleGame.hpp"

void PuzzleGame::drawBoard(){
    for (int i = 0; i < BSZ; i++) {//outer=rows
        for (int j = 0; j < BSZ; j++) {//inner=cols
            cout << board[i * BSZ + j] << " ";
        }
        cout << endl;
    }
}
int PuzzleGame::getChoice() {
    int v;
    cout << "Enter choice: ";
    cin >> v;
    return v;

}
bool PuzzleGame::choiceOK() {
    return true;
}
bool PuzzleGame::checkWinner() {
    //check for winner step 2 check remaining board spaces
    if (!((board[0] == 0 || board[0] == 1) &&
        (board[BSZ2 - 1] == 0 || board[BSZ2 - 1] == BSZ2 - 1))) {
        return false;
    }
    //check for winner step 2 check remaining board spaces
    for (int i = 0; i < BSZ2; i++) {
        if (i > 0 && i < BSZ2 - 1) {
            if ((board[i] != 0 &&
                i > 1 &&
                (board[i - 1] == 0
                    ? board[i] < board[i - 2]
                    : board[i] < board[i - 1]))) {
                // cout << "here" << i << endl;
                return false;
            }
        }
    }
    return true;
}

void PuzzleGame::randomizeBoard() {

}

int PuzzleGame::swap() {
    idv = find(choice);
    id0 = find(0);
    if (idv == -1 || id0 == -1 ) {
        return -1;
    }
    board[id0] = board[idv];
    board[idv] = 0;
    return 0;
}
PuzzleGame::PuzzleGame() {
	brd = &PuzzleBoard(this);
    startUI();
}

int PuzzleGame::find(int searchfor) {
    for (int i = 0; i < BSZ2; i++) {
        if (board[i] == searchfor) {
            return i;
        }
    }
    return -1;
}
void PuzzleGame::startUI() {
	noecho();
	while (!winner) {
		brd->render();
		choice = getch()-'0';
		if (brd->swap() == -1) {
			printw ( "invalid choice");
			continue;
		}
		winner = checkWinner();
		if (winner) {
			brd->render();
			printw( "we have a winner");
		}
	}
}
void PuzzleGame::startGame() {
    while (!winner) {
        drawBoard();
        choice=getChoice();
        if (swap() == -1) {
            cout << "invalid choice" << endl;
            continue;
        }
        winner = checkWinner();
        if (winner) {
            drawBoard();
            cout << "we have a winner" << endl;
        }
    }
}
PuzzlePiece::PuzzlePiece(PuzzleBoard* b, int p,int v){
    brd=b;
    poscode=p;
    number=v;
}

PuzzleBoard::PuzzleBoard(PuzzleGame* g){
	puzzle = g;
    for(int i=0;i<BSZ2; i++){
        pieces[i]={this, i,puzzle->board[i]};
    }
	startpos = Point2D(2, 2);
}

void PuzzleBoard::render() {
	for (int i = 0; i < BSZ2; i++) {
		pieces[i].render();
	}
}

int PuzzleBoard::swap() {
	if (puzzle->swap()==-1) {
		return-1;
	}
	pieces[puzzle->id0].setVal(puzzle->board[puzzle->id0]);
	pieces[puzzle->idv].setVal(puzzle->board[puzzle->idv]);

}

void PuzzlePiece::setVal(int v) {
	number = v;
}

void PuzzlePiece::render() {
	WINDOW* cbox = newwin(3, 5, brd->startpos.my+(poscode/BSZ*3), brd->startpos.mx+(poscode%BSZ*5));
	refresh();
	box(cbox, 0, 0);
	mvwprintw(cbox, 1, 1, " %d",number);
	wrefresh(cbox);	

}

