#include "PuzzleGame.hpp"

PuzzleGame::PuzzleGame(){}

bool PuzzleGame::choiceValid(){
    //choice can be number or letter
    //since we used getch
    choice = choice - '0';//convert back to number/int
    idc = find(choice);
    id0 = find(0);
    if (!(choice >= 0 && choice <= 8)) {
        mvprintw(1, 1, "here %d", choice);
        return false;
    }
    int diff = idc - id0;
    if (!(diff == -3 || diff == 3 || diff == -1 || diff == 1)) {
        mvprintw(1, 1, "%d %d %d", id0,idc,diff);
        return false;
    }
    return true;
}
bool PuzzleGame::checkWin(){
    //check for winner step 2 check remaining board spaces
    if (!((board[0] == 0 || board[0] == 1) &&
        (board[BSZ2 - 1] == 0 || board[BSZ2 - 1] == BSZ2 - 1))) {
        return false;
    }
    //check for winner step 2 check remaining board spaces
    for (int i = 2; i < BSZ2 - 1; i++) {
        if (board[i] == 0)continue;
        if (board[i - 1] == 0
            ? board[i] < board[i - 2]
            : board[i] < board[i - 1]) {
            return false;
        }
    }
    return true;
}
void PuzzleGame::swapPiece(){
    board[id0] = choice;
    board[idc] = 0;
}
void PuzzleGame::drawBoard(){
    for (int i = 0; i < BSZ; i++) {
        for (int j = 0; j < BSZ; j++) {
            cout << board[i * BSZ + j];
        }cout << endl;
    }
}

void PuzzleGame::randomizeBoard(){}

int PuzzleGame::getChoice(){
    cout << "enter value between 0 and 8: ";
    int v; cin >> v;//converts char to int
    return v +'0'; //convert back to char
    return v;
}

int PuzzleGame::find(int sval) {
    //board[] array and arraylength (BSZ2) defined in class
    for (int i = 0; i < BSZ2; i++) {
        if (board[i] == sval)
            return i;
    }
    return -1;
}
void PuzzleGame::startGame() {
    randomizeBoard();
    while (!winner) {
        drawBoard();
        choice = getChoice();
        while (!choiceValid()) {
            cout << "invalid choice, try again.. " << endl;
            choice = getChoice();
        }
        swapPiece();
        winner = checkWin();
        if (winner) {
            break;
        }
    }
    drawBoard();
    cout << "we have a winner!" << endl;
}
void Board::startGame() {
    randomizeBoard();
    noecho();
    while (!winner) {
        render();
        if (winner) {
            mvprintw(1,1,"we have a winner!");
            break;
        }
        choice = getch();
        while (!choiceValid()) {
            //mvprintw(1,1,"invalid choice, try again..");
            choice = getch();
        }
        swapPiece();
        winner = checkWin();
    }
}
/*
private
    2. void checkChoice();
    4. void swapPiece();
    5. void drawBoard();
    6. void randomizeBoard();
    3. bool checkWin();
    7. void getChoice();
public:
    int board[];
    1. PuzzleGame();
    void startGame();

  int board[BSZ2]={1,4,2,6,0,5,7,3,8};//flattened 1D
  while(!winner){ //game loop or game logic
  //disply the board using a nested for loop
    //get input
     //first display enter number
     // declare var for input
     //use standard input cin
   //swap those values
    //*search for the value v
    // declare the index of v as idv
    //search for the zero value
    //declare id0 as the index of 0
   //check for winner
    //check for winner step 1 check first and last board space
      continue;//continue containing loop
    //check for winner step 2 check remaining board spaces
    // done checking for winner
   //printboard one last time
  }//game loop ends here
  //out of the while loop

*/

BoardPiece::BoardPiece(int no,int pos) {
    number = no;
    poscode = pos;
}

void BoardPiece::render() {
    int hoffset = 10;
    int voffset = 5;
    int h = 3,w=5;
    WINDOW* obox = newwin(h, w, voffset+h*(poscode/BSZ), hoffset+w*(poscode%BSZ));
    refresh();
    box(obox, 0, 0);
    mvwprintw(obox, 1, 1, " %d",number);
    wrefresh(obox);
}

Board::Board() {
    for (int i = 0; i < BSZ2; i++) {
        pieces[i] = BoardPiece(board[i], i);
    }
    render();
}

void Board::render() {
    for (int i = 0; i < BSZ2; i++) {
        pieces[i].render();
    }
}
void Board::swapPiece() {
    PuzzleGame::swapPiece();
    pieces[idc].setVal(choice);
    pieces[id0].setVal(0);
}

void BoardPiece::setVal(int v) {
    number = v;
}

