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

void POS::status(string fm, int val){
  const char *fmt = fm.c_str();
  int sz = std::snprintf(nullptr, 0, fmt,val);
  char buf[sz + 1]; // note +1 for null terminator
  std::snprintf(&buf[0], sz+1, fmt, val);
  status(buf);

}
void POS::status(string t){
  move(18,2);clrtoeol();
  mvprintw(18,2, "%s", t.c_str());
  restoreLoc();
}

void POS::status(TxnStatus t){
  switch(t){
  case Success:
    status("Accepted");
    break;
  case InvalidPin:
    status("Invalid Pin");
    break;
  case Created:
    status("Account Created");
    std::this_thread::sleep_for (std::chrono::seconds(1));
    break;
  default:
    status("default at POS::status(tx)");
    return;
  }
}

POS::POS(){
  Rect mainWindow(40,20,1,1);
  mainWindow.Title("WELCOME TO STANDARD BANK");
  mvprintw(5,5,"Enter Amount");
  Rect amtBx(10,3,6,8);
  mvprintw(11,5,"Enter Pin");
  Rect pinBx(10,3,12,8);
  move(pos[cLoc],10);
  getDetails();
}
void POS::cycletab(){
  cLoc=++cycler%L_SIZE;
  restoreLoc();
}

void POS::restoreLoc(){
  switch(cLoc){
  case L_AMT:
    move(pos[cLoc],10+amt.length());
    break;
  case L_PIN:
    move(pos[cLoc],10+pin.length());
    break;
  default:
    status("pos returning from POS::restoreLoc");
    return;
  }
}

void POS::getDetails(){
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
      case ENTER:
        switch(cLoc){
          case L_AMT:
          case L_PIN:{
            float amount=atof(amt.c_str());
            if(amount>0){
              status(createTransaction(pin,amount));
            }else{
              status("Please check amount!");
            }
            break;
          }
          default:
            status("pos returning from default");
            return;
        }break;
      default:
        switch(cLoc){
        case L_AMT:
          if (int(c) != BSP){
            printw("%c", c);
            amt.append(1, c);
          }else{
            amt.pop_back();
            restoreLoc();
            delch();
          }
          break;
        case L_PIN:
          if (int(c) != BSP){
            printw("%c", '*');
            pin.append(1, c);
          }else{
            pin.pop_back();
            restoreLoc();
            delch();
          }
          break;
        default:
          status("pos returning from default");
          return;
        }
        break;
    }
  }
}

