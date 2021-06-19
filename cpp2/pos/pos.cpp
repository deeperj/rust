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
  move(pos[cLoc],10);
}

POS::POS(){
    Rect mainWindow(40,20,1,1);
    mainWindow.Title("WELCOME TO STANDARD BANK");
    mvprintw(5,5,"Enter Amount");
    Rect amtBx(10,3,6,8);
    mvprintw(11,5,"Enter Pin");
    Rect pinBx(10,3,12,8);
    const char *fmt = "sizeof enum = %d size of elem = %d ";
    int sz = std::snprintf(nullptr, 0, fmt, sizeof(LOC),sizeof(L_AMT));
    char buf[sz + 1]; // note +1 for null terminator
    std::snprintf(&buf[0], sz+1, fmt, sizeof(LOC),sizeof(L_AMT));
    move(L_AMT,10);
    processEvents();
}
void POS::cycletab(){
  cLoc=++cycler%L_SIZE;
  move(pos[cLoc],10);
}

void POS::processEvents(){
  keypad(stdscr, true);
  halfdelay(5);
  noecho();
  while (char c = getch()) {
    switch (c) {
      case TAB:
        cycletab();
        break;
      case ESC:
        return;
        break;
      case ERR:
        break;
      default:
        switch(cLoc){
        case L_AMT:
          status("AMT");
          break;
        case L_PIN:
          status("PIN");
          break;
        default:
          status("pos returning from default");
          return;
        }
        break;
    }
  }
}


string POS::getPin(){
  return "";
}