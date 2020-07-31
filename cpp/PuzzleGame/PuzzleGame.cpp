#include "PuzzleGame.hpp"

PuzzleGame::PuzzleGame(){}

bool PuzzleGame::choiceValid(){
    //choice can be number or letter
    //since we used getch
    choice = choice - '0';
    idc = find(choice);
    id0 = find(0);
    if (!(choice >= 0 && choice <= 8)) {
        return false;
    }
    int diff = idc - id0;
    if (!(diff == -3 || diff == 3 || diff == -1 || diff == 1)) {
        return false;
    }
    return true;
}
bool PuzzleGame::checkWin(){
    return false;//dummy implementation
}
void PuzzleGame::swapPiece(){}
void PuzzleGame::drawBoard(){}
void PuzzleGame::randomizeBoard(){}
int PuzzleGame::getChoice(){
    return -1;
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