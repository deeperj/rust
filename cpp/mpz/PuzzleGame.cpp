#include "PuzzleGame.h"

PuzzleGame::PuzzleGame() {
    initscr();
}
void PuzzleGame::layout() {
    int x = 0, y = 0, w = 34, h = 25;
    WINDOW* win = newwin(h, w, y, x);
    refresh();
    move(2, 10);
    printw("Puzzle Game");
    box(win, 0, 0);
    wrefresh(win);

    WINDOW* b1 = newwin(5, 7, 4, 5);
    refresh();
    box(b1, 0, 0);
    wrefresh(b1);

    WINDOW* b2 = newwin(5, 7, 4, 12);
    refresh();
    box(b2, 0, 0);
    wrefresh(b2);

    WINDOW* b3 = newwin(5, 7, 4, 19);
    refresh();
    box(b3, 0, 0);
    wrefresh(b3);

    WINDOW* b4 = newwin(5, 7, 9, 5);
    refresh();
    box(b4, 0, 0);
    wrefresh(b4);

    WINDOW* b5 = newwin(5, 7, 9, 12);
    refresh();
    box(b5, 0, 0);
    wrefresh(b5);

    WINDOW* b6 = newwin(5, 7, 9, 19);
    refresh();
    box(b6, 0, 0);
    wrefresh(b6);

    WINDOW* b7 = newwin(5, 7, 14, 5);
    refresh();
    box(b7, 0, 0);
    wrefresh(b7);

    WINDOW* b8 = newwin(5, 7, 14, 12);
    refresh();
    box(b8, 0, 0);
    wrefresh(b8);

    WINDOW* b9 = newwin(5, 7, 14, 19);
    refresh();
    box(b9, 0, 0);
    wrefresh(b9);

}
void PuzzleGame::drawBoard() {
    for (int i = 0; i < 9; i++) {
        string num;
        if (matrix[i] == '0')
            num = ' ';
        else
            num = matrix[i];
        Point2D point = points[i];
        mvprintw(point.getY(), point.getX(), num.c_str());
    }
}
void PuzzleGame::randomize() {
    srand(time(NULL));
    int size = sizeof(matrix) / sizeof(matrix[0]);
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = matrix[j];
        matrix[j] = matrix[i];
        matrix[i] = temp;
    }
}
void PuzzleGame::getChoice() {
    mvprintw(20, 3, "Enter a number: ");
    move(20, 20);
    choice = getch();
    if (!(choice == '0' || choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6' || choice == '7' || choice == '8')) {
        mvprintw(21, 3, "Not Valid. Enter Again");
        getChoice();
    }
}
int PuzzleGame::findElement(char num) {
    for (int i = 0; i < sizeof(matrix); i++) {
        if (matrix[i] == num)
            return i;
    }
}
bool PuzzleGame::checkChoice() {
    indexChoice = findElement(choice);
    index0 = findElement('0');
    int diff = indexChoice - index0;
    if (diff == -3 || diff == 3 || diff == -1 || diff == 1)
        return true;
    else {
        mvprintw(21, 3, "Not Valid. Enter Again");
        return false;
    }

}
void PuzzleGame::swap() {
    matrix[indexChoice] = '0';
    matrix[index0] = choice;
}
bool PuzzleGame::checkWin() {
    if (!(matrix[0] == '1' && matrix[8] == '0'))
        return false;
    else if (matrix[1] == '2' && matrix[2] == '3' && matrix[3] == '4' && matrix[4] == '5' && matrix[5] == '6' && matrix[6] == '7' && matrix[7] == '8')
        return true;
    else
        return false;
}
void PuzzleGame::playGame() {
    layout();
    randomize();
    drawBoard();

    while (1) {
        bool choiceCorrect = false;
        while (!choiceCorrect) {
            getChoice();
            choiceCorrect = checkChoice();
        }
        mvprintw(21, 3, "                       ");
        swap();
        drawBoard();
        if (checkWin() == true) {
            mvprintw(20, 3, "                   ");
            mvprintw(21, 10, "You win!");
            getch();
            endwin();
            return;
        }
    }





    getch();
}