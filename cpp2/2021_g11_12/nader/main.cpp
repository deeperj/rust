#include <iostream>
#include<list>
#include <curses.h>
#include <cstring>
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

class User
{
  private: 
    string username;
    string password;
    string Fvcolour;

  public:
  
  User(string _username , string _password, string _Fvcolour)
  {
        username = _username;
        password = _password;
        Fvcolour = _Fvcolour;
  }

  void setusername(string _username)
  {
    username = _username;
  }

  string getusername()
  {
    return username;
  }

  void setpassword(string _password)
  {
    this->password = _password;
  }

  string getpassword()
  {
    return password;
  }

  void setFvcolour(string _Fvcolour){
    Fvcolour = _Fvcolour;
  }
  string getFvcolour(){
    return Fvcolour;
  }
};

class Authentication 
{
    private:
    list<User> usersList;
    
    public:
    ofstream users;
    
  void addUser(string _username, string _password , string fav  )
  {
    users.open("users.csv", std::ios_base::app);
    usersList.push_back(User(_username, _password, fav));
    users << _username <<","<< _password<<","<<fav<<"\n";
    users.close();
  }
  

  void split(string line, list<string> &result)
  {
      int i = 0;

      while(i < line.size() && line[i] != ',')
        i++;
      
      if(i == line.size())
        result.push_back(line);

      string temp = line.substr(0,i);
      result.push_back(temp);
      if(i+1 < line.size())
        split(line.substr(i+1), result);
  }

  void UpdateFile(list<User> usersUpdatedList)
  { 
    std::ofstream ofs;
    ofs.open("users.csv");
    ofs.close();

    for(User user: usersUpdatedList)
    { 
      string username = user.getusername();
      string password = user.getpassword();
      string color = user.getFvcolour();

      addUser(user.getusername(), user.getpassword(), user.getFvcolour());
    }
  }

 void readUsersFromFile()
  {
    fstream fin;
    
    fin.open("users.csv", ios::in);
    string line;
    ifstream users ("users.csv");

    if(users.is_open())
    {  
      while(getline(users, line))
      {
        list<string> *currentUser = new list<string>;
        split(line, *currentUser);

        std::list<std::string>::iterator it = currentUser->begin();
        std::advance(it, 0);
        string username = *it;

        std::advance(it, 1);
        string password = *it;

        std::advance(it, 2);
        string color = *it;

        usersList.push_back(User(username, password, color));
      }
    }
    fin.close();
    
  }

  bool login( string _username , string _password)
  {
    readUsersFromFile();
    bool foundUser = false;
    for(User user: usersList)
    {
      if( _username == user.getusername())
      {
        if (_password==user.getpassword() )
        {
          cout<<"signed in succesfully"<<endl;
          return true;
        }
      }
    }

    cout<<"invalid username or password"<<endl;
    return false;
  }

  bool Register(string _username , string _password , string _FavColour){
    bool Userfound = false;

    readUsersFromFile();

    for(User user: usersList)
    {
      if (_username == user.getusername()){
        Userfound = true ;
        cout<<"Username already taken please try again"<<endl;
        return false;
      }
    }
    if ( !Userfound ){
      
      
      addUser(_username , _password , _FavColour);
        cout<<"**you registered succesfully**"<<endl;        
        return true;
    }
        
  }


  bool ForgetPassword( string _username , string _password, string FavColour )
  {
    readUsersFromFile();
    bool result = false;
    list<User> usersUpdatedList;

    for (User user: usersList)
    {
      if (_username == user.getusername())
      {
          if(FavColour == user.getFvcolour())
        {

          user.setpassword(_password);
          result = true;

        }
        else 
        {
          cout<<"Wrong Colour"<<endl;

        }
      }
      usersUpdatedList.push_back(User(user.getusername(), user.getpassword(), user.getFvcolour()));
    }

    if(result)
    {
      UpdateFile(usersUpdatedList);
    
      return result;
    }
    else
    {
      cout << "Invalid username or favourite colour";
      return false;
    }
  }
};





int main() 
{ 
  int Index=0; 
  Authentication authentication;
  
  //authentication.addUser("ghandoor" , "yarab" , "red" , 0);
  //authentication.login2("ghandoor" , "yarab");
  int choice;
  string _Username;
  string _Password;
  string _FavouriteC;
 initscr();
WINDOW * menuwin = newwin( 20 , 20 , 10, 10);
box(menuwin , 0, 0);
refresh();
wrefresh(menuwin);
keypad(menuwin, true);

string choices[4] = {"login" , "Register ", "forget password", "Exit"};

int highlight = 0;

 while(1){
   for(int i = 0; i<4; i++)
   {
     if ( i == highlight)
     
       wattron(menuwin , A_REVERSE);
       mvwprintw( menuwin , i + 1 ,  1  , choices[i].c_str() );
       wattroff(menuwin , A_REVERSE);     
     
   }
    choice = wgetch(menuwin);

      switch(choice)
      {
        case KEY_UP:
        highlight --;
        if( highlight == -1)
        highlight=0;
        break;

        case KEY_DOWN:
        highlight++;
        if(highlight == 4)
        highlight = 3;
        break;

        default:
        break;
      }
      if (choice == 10){
        break;
      }
   }
 printw("your choice was: %s" , choices[highlight].c_str());

endwin();
  if ( highlight == 0)
  {
    for (int i = 0 ; i <= 1000; i++)
    {
      cout<< "please enter username" <<endl;
      cin>>_Username;
      cout<<"please enter your password"<<endl;
      cin>>_Password;
      bool loginSuccessful = authentication.login(_Username, _Password);
      if(loginSuccessful)
       break;
      
    }
  }
  else if (highlight ==1){
    for (int inc=0 ;;){
    cout<< "please enter username" <<endl;
    cin>>_Username;
    cout<<"please enter your password"<<endl;
    cin>>_Password;
    cout<<"please enter your Favourite colour"<<endl;
    cin>>_FavouriteC;
    bool RegisterSuccessful = authentication.Register(_Username , _Password , _FavouriteC);

    if (RegisterSuccessful){
      break;
    }
    
    }
  }
  else if (highlight == 2){
    bool forgetsuccess = false;
    for(int I=0;;){
    cout <<"Please enter your username"<<endl;
    cin>>_Username;
    cout<< "Please enter your Favourite colour"<<endl;
    cin>>_FavouriteC;
    cout<<"Please enter your new password"<<endl;
    cin>>_Password;
    forgetsuccess= authentication.ForgetPassword( _Username,  _Password , _FavouriteC );

    if(forgetsuccess)
      break;
    
    }

  }
  else if (highlight == 3)
  {
  
  }
}
