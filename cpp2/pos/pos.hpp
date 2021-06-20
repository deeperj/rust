#pragma once

#include "psys.hpp"

enum CUR {C_AMT=7,C_PIN=13};
enum LOC {L_AMT,L_PIN,L_SIZE};
enum keyb{TAB=9,ENTER=10,BACK=126,SPC=' ',ESC=27,BSP=8};

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
    Rect(){}
    void Title(string );
};

class POS: public Bank{
  private:
    int cLoc=L_AMT;
    int cycler=0;
    void getDetails();
    void restoreLoc();
    void cycletab();
    int pos[L_SIZE]={C_AMT,C_PIN};
    string amt;
    string pin;
  public:
    POS();
    void status(string);
    void status(string,int);
};

