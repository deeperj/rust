#include "pos.hpp"

Rect::Rect(int width, int height, int top, int left){
  w=width;
  h=height;
  x=left;
  y=top;
  drawRect();
}

Rect::Rect(string t, int top, int left){
  w=t.length()+2;
  h=3;
  x=left;
  y=top;
  drawRect();
  Title(t);
}

void Rect::drawRect(){
  win = newwin(h,w,y,x);
  refresh();
  box(win,0,0);
  wrefresh(win);
}

void Rect::Title(string t){
  title=t;
  wmove(win,1,1);clrtoeol();
  mvwprintw(win, 1,1, "%s", t.c_str());
  wrefresh(win);
}

void POS::status(string t){
  move(18,2);clrtoeol();
  mvprintw(18,2, "%s", t.c_str());
}

POS::POS(){
    Rect mainWindow(40,20,1,1);
    mainWindow.Title("WELCOME TO STANDARD BANK");
    mvprintw(5,5,"Enter Amount");
    Rect amtBx(10,3,6,8);
    mvprintw(11,5,"Enter Pin");
    Rect pinBx(10,3,12,8);
    //status("welcome to standard bank POS");
    move(7,10);
    processEvents();
}
void POS::cycletab(){
  int pos[2]={AMT,PIN};
  move(pos[cycler++%2],10);
}

void POS::processEvents(){
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

