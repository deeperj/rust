#ifndef AMTUI_H
#define AMTUI_H

#include "AuthManager.h"


class Point2D {
public:
    int mx, my;
    Point2D(int X, int y) :mx(X), my(y) {};
    int X() { return mx - 1; }
    int Y() { return my - 1; }
};
class AssertErr {};
class Amtui {
private:
    AuthManager a;
    enum  Screen { Home, Reg, Login, Reset, Sess, Err };
    enum  tab_cycler { ebx, pbx, vbx, mbx, obx, cbx };
    vector<tab_cycler> idx;
    vector<Point2D> tab;
    vector<Point2D> t = { Point2D(21,7),Point2D(21,10)
                    ,Point2D(21,16)
                    ,Point2D(21,13)
                    ,Point2D(15,4),Point2D(35,4)
    };
    Point2D tbx = Point2D(20, 3);
    Point2D ocb = Point2D(10, 3);
    Point2D wsz = Point2D(65, 25);
    Point2D sln = Point2D(4, 21);
    int fieldindent = 4;
    int tabc = 0;
    int fc = tab.size();
    bool testing = false;
    WINDOW* win;
    void init();
    void displayEmail();
    void displayPassword();
    void displayPassword2();
    void displayOkCancel();
    void displayHome();
    void cycletab();
    void cycleback();
    void display(Screen);
    void eventLoop();
    void displayLogin();
    void displayReg();
    void displayForgotPass();
    void displaySession();
    void displayMaiden();
    void okHandle();
    void uitext(WINDOW* win, Point2D loc, string txt);
    int id(tab_cycler t);
    void configure(Point2D p[], tab_cycler t[], int size);
public:
    friend class Test;
    static int wc;
    static bool initialised;
    Amtui() {};
    ~Amtui();
    void drawBorder();
    void banner();
    void run();
    void display();
};

#endif