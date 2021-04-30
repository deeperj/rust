#include "point2d.h"
#include <assert.h>
#include <iostream>
#include <curses.h>

using std::cout;
using std::endl;
using std::string;
using std::cout;
enum tab_cycler { ebox, pbox, obox, cbox };
string email;
string pword;
Point2D gotab[] = { Point2D(21,4),Point2D(21,7),Point2D(15,10),Point2D(35,10) };
int tabc = 0;
void displayLogin() {
     // initialise
     // setup memory and clear screen
     // refresh screen to match memory
     int x = 0, y = 0, w = 60, h = 25;
     WINDOW* win = newwin(h, w, y, x);
     refresh();
     move(1, 1);
     printw("LOGIN WINDOW!");
     box(win, 0, 0);
     wrefresh(win);
}
void displayEmail() {
     mvprintw(4, 4, "User email");
     WINDOW* ebox = newwin(3, 20, 3, 20);
     refresh();
     box(ebox, 0, 0);
     wrefresh(ebox);
}
void displayPassword() {
     mvprintw(7, 4, "User Password");
     WINDOW* pbox = newwin(3, 20, 6, 20);
     refresh();
     box(pbox, 0, 0);
     wrefresh(pbox);
}
void displayOkCancel() {
     WINDOW* obox = newwin(3, 10, 9, 14);
     refresh();
     box(obox, 0, 0);
     mvwprintw(obox, 1, 1, "   Ok");
     wrefresh(obox);
     WINDOW* cbox = newwin(3, 10, 9, 34);
     refresh();
     box(cbox, 0, 0);
     mvwprintw(cbox, 1, 1, " Cancel");
     wrefresh(cbox);
}
void cycletab() {
     int i = tabc++ % 4;
     move(gotab[i].my, gotab[i].mx);
}
void backcycletab() {
     int i;
     if (tabc%4 == 1) {
          i = 3; tabc = 4; 
     }
     else {
          tabc -= 1;
          i = (tabc%4) - 1;
     } 
     move(gotab[i].my, gotab[i].mx);
}
void eventLoop() {
     halfdelay(5);
     noecho();
     cycletab();
     while (char c = getch()) {
          if (c == ERR)continue;
          int tab = (tabc % 4 == 0) ? 3 : tabc % 4 - 1;
          assert(tab >= 0 && tab < 4);
          // printw("%d %c",int(c),-53); 
          switch (c) {
               case ' ':
               case 10:
               case -53:
                    if (c == ' ') {
                         if (tab == obox)return;
                         if (tab == cbox) {
                              email = "<no input>";
                              pword = "<no input>";
                              return;
                          }
                          printw("%c", c);
                          email.append(1, c);
                          break;
                     }
                     if (tab == obox)return;
                     if (tab == cbox) {
                          email = "<no input>";
                          pword = "<no input>";
                          return;
                      }
                      break;
               case 126:
                    backcycletab();
                    break;
               case 9:
                    cycletab();
                    break;
               default:
                    switch (tab) {
                         case ebox:
                              if (int(c) != 127)printw("%c", c);
                              email.append(1, c);
                              break;
                          case pbox:
                               if (int(c) != 127)printw("%c", '*');
                               pword.append(1, c);
                               break;
                      }
          }
     }
}
int main() {
     initscr();
     keypad(stdscr, TRUE);
     displayLogin();
     displayEmail();
     displayPassword();
     displayOkCancel();
     eventLoop();
     //deallocate memory and ends ncurses
     endwin();
     cout << "email received was : " << email << endl;
     cout << "passw obtained was : " << pword << endl;
     return 0;
}