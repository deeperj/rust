#include "Header.h"

// Creating the window means the outlook of the consol.
void UserInterface::CreateWindow(const char* windowName ) {
	initscr();

	WINDOW* win = newwin(25, 60, 0, 0); 
	move(1, 1);
	box(win, 0, 0);
	refresh(); 	
	wrefresh(win);
}
// Creating Button for the user which helps to go into the required option.
void UserInterface::CreateButton(int Xpos, int Ypos, const char* buttonName) {
	WINDOW* obox = newwin(3, 18, Ypos, Xpos);
	refresh();
	box(obox, 0, 0);
	mvwprintw(obox, 1, 1, buttonName);
	wrefresh(obox);
}
// Creating a TextBox on which the user will enter the required information.
void UserInterface::CreateTextBox(int Xpos, int Ypos, const char* nameBox) {
	mvprintw(Ypos, Xpos, nameBox);

	WINDOW* TextBox = newwin(3, 20, Ypos - 1, Xpos + 25); 
	refresh();
	box(TextBox, 0, 0);
	wrefresh(TextBox);
}
// Creating the functions to control the Main screen. 
void UserInterface::eventLoopMain() {
    halfdelay(5);
    noecho();
    Cycle(MainPositions, 4);
    while (int keyPressed = getch()) {
        if (keyPressed == ERR) continue;
        switch (keyPressed) {
        case 126:
        //Shift+Tab
        case 259:
        //up Arrow
            CounterCycle(MainPositions, 4);
            break;
        case 9:
        //Tab
        case 258:
        //Down Arrow
            Cycle(MainPositions, 4);
            break;
        default:
          switch (CursorPosition) {
            case 0: //Case 0 = Cursor is on Login Button 
              //keyPressed == 10 (The user pressed enter)
              if (keyPressed == 10) { LoginPage(); } 
              break;
            case 1: //Case 1 = Cursor is on Register button
              if (keyPressed == 10) { Signup();}
              break;
            case 2: //Case 2 = Cursor is on Exit Button 
              if (keyPressed == 10) { ResetPage(); } 
              break;
              //case 3: //Case 2 = Cursor is on Exit Button 
              //if (keyPressed == 10) { ExitPage(); } 
              //break;
              case 3: //Case 2 = Cursor is on Exit Button 
              if (keyPressed == 10) { endwin(); exit(0); } 
              break;
            }
        }
    }
}

// Creating the functions to control the Login page.
void UserInterface::eventLoopLogin() {
    CurrentUser.username = "";
    CurrentUser.password = "";



    string test1;
    halfdelay(5);
    noecho();
    Cycle(LoginPositions, 5);
    while (int keyPressed = getch()) {
        if (keyPressed == ERR) continue;
        switch (keyPressed) {
        case 126:
        //Shift+Tab
        case 259:
        //up Arrow
            CounterCycle(LoginPositions, 5);
            break;
        case 9:
        //Tab
        case 258:
        //Down Arrow
            Cycle(LoginPositions, 5);
            break;
        default:
          switch (CursorPosition) {
            case 0: //The user is in the Username			}
            if (keyPressed != 32) { //As long as the user doesn't press spacebar (32)
              printw("%c", keyPressed); 
              CurrentUser.username.append(1, keyPressed);
            }
            
            break;
            case 1: //The user is in the Username			}
              if (keyPressed != 32) { //As long as the user doesn't press spacebar (32)
                printw("%c", '*'); 
                CurrentUser.password.append(1, keyPressed);
				      }
            break;
            
             case 2: 
              if (keyPressed == 10) { ResetPage(); } 
              break;

              case 3: //Cancel
              if (keyPressed == 10) { MainPage(); } 
              break;

              case 4: //Login
              if (keyPressed == 10) {
                if (CurrentSession.CheckLoginDetails(CurrentUser.username, CurrentUser.password) == 0){
                  mvprintw(13, 20, "Login Information Wrong");
                }
                else mvprintw(13, 20, "Welcome back");




              } //CheckLogin(); } 
              break;


              
            
            }
        }
    }
}

void UserInterface::eventLoopSignup() {
    CurrentUser.username = "";
    CurrentUser.password = "";
    CurrentUser.maidens_name = "";


    string test1;
    halfdelay(5);
    noecho();
    Cycle(SignupPositions, 5);
    while (int keyPressed = getch()) {
        if (keyPressed == ERR) continue;
        switch (keyPressed) {
        case 126:
        //Shift+Tab
        case 259:
        //up Arrow
            CounterCycle(SignupPositions, 5);
            break;
        case 9:
        //Tab
        case 258:
        //Down Arrow
            Cycle(SignupPositions, 5);
            break;
        default:
          switch (CursorPosition) {
            case 0: //The user is in the Username			}
            if (keyPressed != 32) { //As long as the user doesn't press spacebar (32)
              printw("%c", keyPressed); 
              CurrentUser.username.append(1, keyPressed);
            }
            break;

            case 1: //The user is in the Password			}
              if (keyPressed != 32) { //As long as the user doesn't press spacebar (32)
                printw("%c", '*'); 
                CurrentUser.password.append(1, keyPressed);
				      }
             break;
              
              case 2: //The user is in the Mother MAuden's Name		}
            if (keyPressed != 32) { //As long as the user doesn't press spacebar (32)
              printw("%c", keyPressed); 
              CurrentUser.maidens_name.append(1, keyPressed);
            }
            break;
            
            case 3: //Cancel
              if (keyPressed == 10) { MainPage(); } 
              break;
            
          
            }

            case 4: //Signup
              if (keyPressed == 10) {  

                if(CurrentSession.CheckSignupDetails(CurrentUser.username) == 0){
                   mvprintw(16, 20, "Username already taken");
                }
                else{
                  CurrentSession.SaveAccount(CurrentUser.username, CurrentUser.password, CurrentUser.maidens_name);
                  mvprintw(16, 20, "Your account has been saved");
                }


              } //Not finished
              break;
        }
    }
}

void UserInterface::eventLoopReset() {
  CurrentUser.username = "";
    CurrentUser.password = "";
    CurrentUser.maidens_name = "";


    string test1;
    halfdelay(5);
    noecho();
    Cycle(ResetPositions, 5);
    while (int keyPressed = getch()) {
        if (keyPressed == ERR) continue;
        switch (keyPressed) {
        case 96:
        // ` 
            CounterCycle(ResetPositions, 5);
            break;
        case 9:
        //Tab
            Cycle(ResetPositions, 5);
            break;
        default:
          switch (CursorPosition) {
            case 0: //The user is in the Username			}
            if (keyPressed != 32) { //As long as the user doesn't press spacebar (32)
              printw("%c", keyPressed); 
              CurrentUser.username.append(1, keyPressed);
            }
            
            break;
            case 1: //The user is in the Username			}
              if (keyPressed != 32) { //As long as the user doesn't press spacebar (32)
                printw("%c", keyPressed); 
                CurrentUser.maidens_name.append(1, keyPressed);
				      }
            break;
              
            case 2: //The user is in the Username			}
              if (keyPressed != 32) { //As long as the user doesn't press spacebar (32)
                printw("%c", '*'); 
                CurrentUser.password.append(1, keyPressed);
				      }
            break;

            case 3: //The user is in the Username			}
              if (keyPressed != 32) { //Cancel
                 
                MainPage();
				      }
            break;

            case 4: //The user is in the Username			}
              if(CurrentSession.CheckResetDetails(CurrentUser.username, CurrentUser.password, CurrentUser.maidens_name) == 0){
                   mvprintw(16, 20, "Invalid information");
                }
                else mvprintw(16, 20, "Password has been reset");


				      
            break;
            }
        }
    }
}
void UserInterface::Cycle(Point2D Positions[], int numberSpaces) {
  CursorPosition++; 
	if (CursorPosition >= numberSpaces) {
      CursorPosition = 0;
	  }
	move(Positions[CursorPosition].my, Positions[CursorPosition].mx);
}

void UserInterface::CounterCycle(Point2D Positions[], int numberSpaces) {
    CursorPosition--; 
	  if (CursorPosition < 0) { 
		  CursorPosition = numberSpaces - 1; 
   }
   move(Positions[CursorPosition].my, Positions[CursorPosition].mx);
}


// This page will dispaly Main page page
void UserInterface::MainPage(){
  CreateWindow("");
  mvprintw(3, 19, "Hello Users");
  CreateButton(17,8, "Login");
  CreateButton(17,12, "Sign-up");
  CreateButton(17,16, "Reset Password");
  CreateButton(17,20, "Exit");

  eventLoopMain();
 
}

// This page will dispaly Login page
void UserInterface::LoginPage(){
  CreateWindow("");
  mvprintw(3 , 25, "Login");
  CreateTextBox(5,7 ,"Username" );
  CreateTextBox(5,10 ,"Password" );
  CreateButton(6,17, "Forgot Password");
  CreateButton(20,20, "Login");
  CreateButton(30,17, "Cancel");
  

  CursorPosition = -1;
  eventLoopLogin();
 
}
// This page will dispaly Sign up page
void UserInterface::Signup(){
  CreateWindow("");
  mvprintw(3 , 25, "Sign up");
  CreateTextBox(5,7 ,"Username" );
  CreateTextBox(5,10 ,"Create Password" );
  CreateTextBox(5,14, "Mother Maiden's Name");
  CreateButton(30,18, "Sign up");
  CreateButton(5,18, "Cancel");
  

  CursorPosition = -1;
  eventLoopSignup();
 
}
// This page will dispaly Reset PAssword page
void UserInterface::ResetPage(){
  CreateWindow("");
  mvprintw(3 , 25, "Reset Password");
  CreateTextBox(5,7 ,"Username" );
  CreateTextBox(5,10 ,"Mother Maiden's Name" );
  CreateTextBox(5,13, "New Password");
  CreateButton(6,17, "Cancel");
  CreateButton(30,17, "Reset Password");
  

  CursorPosition = -1;
  eventLoopReset();
 
}
 

