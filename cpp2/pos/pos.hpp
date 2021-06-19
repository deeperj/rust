#pragma once

#include <curses.h>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

enum CUR {AMT=7,PIN=13};
enum keyb{TAB=9,ENTER=10,BACK=126,SPC=' ',ESC=27};

class Rect{
  private:
    string title;
    WINDOW *win;
    int w;
    int h;
    int x;
    int y;
    void drawRect();
  public:
    Rect(int width, int height, int top, int left);
    Rect(string t, int top, int left);
    void Title(string );
};

class POS{
  private:
    int cycler=0;
    void processEvents();
    void cycletab();
  public:
    POS();
    void status(string);
};

