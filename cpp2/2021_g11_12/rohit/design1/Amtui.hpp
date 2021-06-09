#ifndef AMTUI_H
#define AMTUI_H

#include "authmgr.h"
#include "point2d.h"


class Amtui : public Manager {
private:
    enum  Screen { Home, Reg, Login, Reset, Sess, Err };
    enum  tab_cycler { ebx, pbx, vbx, obx, cbx };
    vector<tab_cycler> idx;
    vector<Point2D> tab = { Point2D(7,21),Point2D(10,21)
                    ,Point2D(13,21)
                    ,Point2D(4,15),Point2D(4,35)
    };
    Point2D tbx = Point2D(3, 20);
    Point2D ocb = Point2D(3, 10);
    Point2D wsz = Point2D(65, 25);
    Point2D sln = Point2D(16, 21);
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
    void displaySession();
    void drawBorder();
    void banner();
    void okHandle();
    void uitext(WINDOW* win, Point2D loc, string txt);
    void configure(Point2D p[], tab_cycler t[], int size);
    int id(tab_cycler t);

public:
    //friend class Test;
    static int wc;
    static bool initialised;
    Amtui();
    ~Amtui();
    void run();
    void display();
};
class AssertErr{

};

#endif
