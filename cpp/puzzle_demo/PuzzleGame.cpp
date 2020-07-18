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

void PuzzleGame::randomizeBoard() {

}
PuzzleGame::PuzzleGame() {
    startGame();
}

int PuzzleGame::find(int searchfor) {
    for (int i = 0; i < BSZ2; i++) {
        if (board[i] == searchfor) {
            return i;
        }
        else {
            return -1;
        }
    }
}

void PuzzleGame::startGame() {
    while (!winner) {
        drawBoard();
        getChoice();
    }
}