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
        (board[BSZ2 - 1] == 0 || board[BSZ2 - 1] == 8))) {
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
    //cout << choice << " " << idv << " " << id0 << endl;
    if (idv == -1 || id0 == -1 ) {
        return -1;
    }
    board[id0] = board[idv];
    board[idv] = 0;
    return 0;
}
PuzzleGame::PuzzleGame() {
    startGame();
}

int PuzzleGame::find(int searchfor) {
    for (int i = 0; i < BSZ2; i++) {
        if (board[i] == searchfor) {
            return i;
        }
    }
    return -1;
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