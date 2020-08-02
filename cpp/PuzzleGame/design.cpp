#include "PuzzleGame.hpp"
#include "Test.h"

int main()
{
  cout << "PuzzleGame files added!" << endl;
  cout << "Puzzle dummy implementation in progress!" << endl;
  initscr();
  WINDOW* obox = newwin(3, 10, 9, 14);
  refresh();
  box(obox, 0, 0);
  mvwprintw(obox, 1, 1, "   Ok");
  wrefresh(obox);
  getch();
  endwin();
  Test t;
  t.testall();
}
