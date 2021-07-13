#include "PuzzleGame.hpp"

void BoardSquare::render() {
	WINDOW* cbox = newwin(3, 5, bpos.my+(poscode/BSZ*3), bpos.mx+(poscode%BSZ*5));
	refresh();
	box(cbox, 0, 0);
	mvwprintw(cbox, 1, 1, " %d",number);
	wrefresh(cbox);	
}
void BoardSquare::setVal(int v) {
	number = v;
}

int BoardSquare::val() {
	return number;
}

BoardSquare::BoardSquare(Point2D b, int p,int v){
    bpos=b;
    poscode=p;
    number=v;
}

Board::Board(Point2D p){
    startpos=p;
    for(int i=0;i<BSZ2; i++){
        squares[i]={startpos, i, i+1};
    }
}
void Board::render() {
	for (int i = 0; i < BSZ2; i++) {
		squares[i].render();
	}

}

PuzzleGame::PuzzleGame(){
  board = {Point2D(1,1)};
}
const int PuzzleGame::find(const int haystack[], int needle, int size){
  for(int i = 0; i < size; i++){
    if(needle==haystack[i]){
      return i;
    }
  }
  return -1;
}

void PuzzleGame::startGame(){
    // procedure startGame()
    // :call randomizeBoard();
    // :call displayBoard();
    // declare winner=false;
    // while(!winner) then
    // do //post-test loop(iteration)
    // :call getInputFromUser();
    // :call isValid=checkInput();
    // if(!isValid) then
    //     :cout<<"invalid input" << endl;
    // :end if
    // while(!isValid) end
    // swapPiece()
    // winner =call gameEnding()
    // end while
    // :cout << "Congratulations you won !" << endl;
    // end proceudure 
}

