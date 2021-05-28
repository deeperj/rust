#include <string>
#include <iostream>
#include "curses.h"

using namespace std;


class Point2D {
public:
    int mx, my;
    Point2D();
    Point2D(int x, int y) {
        mx = x;
        my = y;
    };
};
// user class for initialization variables to be used in the code.
class user{
public:
  string username;
  string password;
  string maidens_name;
};

// Entering Random Data into the database for current use.
class Database{
  public:
    string Usernames[10]= {"Talha", "Fran","John","Jamila"};
    string password[10] = {"00000","11111","22222","33333"};
    string maidens_name[10] = {"nasreen","maria","john","momaniyat" };

};
// SessionManager helps to check the conditions.
class SessionManager{
  public:

    bool CheckLoginDetails(string username, string password);
    bool CheckSignupDetails(string username);
    void SaveAccount(string username, string password, string mother);
    bool CheckResetDetails(string username, string newPassword, string maidenName);
    void UpdatePassword(int index, string newPassword);

    Database Data;
};

//This class contains the functions which are being called to use and the cursor initialization and positioning. 
class UserInterface{
  public:
    user CurrentUser;
    SessionManager CurrentSession;

    void MainPage();
    void LoginPage();
    void Signup();
    void ResetPage();
    void ExitPage();

    void CreateButton(int Xpos, int Ypos, const char* buttonName);
    void CreateTextBox(int Xpos, int Ypos, const char* nameBox);
    void CreateWindow( const char* windowName );
    void Cycle(Point2D Positions[], int numberSpaces);
    void CounterCycle(Point2D Positions[], int numberSpaces);
    void eventLoopMain();
    void eventLoopLogin();
    void eventLoopReset();
    void eventLoopSignup();

  public:
    int CursorPosition = -1;

      Point2D MainPositions[4] {Point2D(30,9), Point2D(30,13),Point2D(33,17),Point2D(30,21)};

     Point2D LoginPositions[5] {Point2D(31,7), Point2D(31,10),Point2D(22,18),Point2D(37,18),Point2D(28,21)};

     Point2D SignupPositions[5] {Point2D(31,7), Point2D(31,10),Point2D(31,14),Point2D(19,19),Point2D(41,19)};

     Point2D ResetPositions[5] {Point2D(31,7), Point2D(31,10),Point2D(31,13),Point2D(19,18),Point2D(46,18)};

};
