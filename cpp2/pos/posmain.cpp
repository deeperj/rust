#include <curses.h>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
  initscr();
  WINDOW *win = newwin(20,40,1,1);//(h,w,y,x)
  refresh();
  box(win,0,0);
  wrefresh(win);
  getch();
  endwin();
  //cout << "hello" << endl;
  return 0;
}