#include <iostream>
#include <curses.h>

void drawWin(int h, int w, int y, int x);
void drawLogin();
void eventloop();
void cycletab();

enum SYM {USRNAME,PASSWRD,DOK};
enum POS {UPOS=11,PPOS=16,OPOS=21};
enum keyb{TAB=9,ENTER=10,BACK=126,SPC=' ',ESC=27};
int cycler=0;

int main() 
{
  initscr(); //clear the screen
  //std::cout << "Hello World!\n";

  drawLogin();

  eventloop();
  endwin(); //clean up
}

void drawLogin(){
  //Big Rectangle 
  drawWin(24,60,0,0);

  mvprintw(5,25,"Login Manager");

  //Rectangle 1
  drawWin(3,30,10,5); 
  mvprintw(11,6,"Username");
  //(Height, Width, Y Position, X Position)

  //Rectangle 2
  drawWin(3,30,15,5);
  mvprintw(16,6,"Password");

  //Rectangle 3
  drawWin(3,30,20,5);
  mvprintw(21,6,"Ok");
}

void drawWin(int h, int w, int y, int x)
{
  WINDOW* win = newwin(h,w,y,x);// (h,w,y,x)
  refresh();
  box(win,0,0);
  wrefresh(win);
}

void cycletab(){
  int pos[3]={UPOS,PPOS,OPOS};
  move(pos[cycler++%3],20);
}
void eventloop() {
  keypad(stdscr, true);
  halfdelay(5);
  noecho();
  while (char c = getch()) {
    // if(c==ERR){move(1,1);clrtoeol();continue;}
    // mvprintw(1,1,"%d",c);
    switch (c) {
      case TAB:
        cycletab();
        break;
      case ESC:
        return;
        break;
      default:
        break;
    }
  }
}
