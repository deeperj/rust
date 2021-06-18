#include <curses.h>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
  initscr();


  endwin();
  cout << "hello" << endl;
  return 0;
}