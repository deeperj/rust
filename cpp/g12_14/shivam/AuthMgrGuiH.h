#ifndef AUTHMGRGUIH_H_INCLUDED
#define AUTHMGRGUIH_H_INCLUDED

//Header Files Included
#include<iostream>
#include<string.h>

using namespace std;


//global variable
char match[20];

// function to enter password
void pass()
  {
    int i,x;
    char ch='/0';
    for(i=0;i>=0;)
     {
       ch=getch();

      if(ch!=8&&ch!=13)
        {
         cout<<"*";
         match[i]=ch;
         i++;
        }
      else if (ch==8) // if backspace is presssed
       {
         cout<<"\b \b"; // moves cursor to the left print <space> again move cursor to left
         i--;
       }
      else if(ch==13)
    {
         match[i]='\0'; // if enter is pressed, last character in match[] becomes null
        break;         // for end of string
    }
    else
    {
         break;
    }
  }

}

// class implementation
class AuthMgrGui
{
private:
	Manager mgr;
public:
	void Display()
	{
Details user;
int ch;
while(1)
{
cout<<endl<<endl<<"1 Register"<<endl;
cout<<"2 Login"<<endl;
cout<<"3 Forgot Password"<<endl;
cout<<"4 Reset Password"<<endl;
cout<<"5 Exit"<<endl<<endl;

cout<<"Enter your choice ";
cin>>ch;

switch(ch)
{
case 1:
cout<<endl;
cout<<"Enter Email  :  ";
cin>>user.UserEmail;
cout<<"Enter Password   :   ";
pass();
strcpy(user.UserPassword,match);
cout<<endl<<"Enter Mother's Maiden Name   :   ";
cin>>user.MotherMaidenName;
mgr.Register(user);
break;

case 2:
cout<<endl;
cout<<"Enter Email  :  ";
cin>>user.UserEmail;
cout<<"Enter Password   :   ";
pass();
strcpy(user.UserPassword,match);
mgr.login(user);
break;

case 3:
cout<<endl;
cout<<"Enter Email  :  ";
cin>>user.UserEmail;
cout<<"Enter Mother's Maiden Name   :   ";
cin>>user.MotherMaidenName;
mgr.requestReset(user);

break;

case 4:
cout<<endl;
cout<<"Enter Email  :  ";
cin>>user.UserEmail;
cout<<"Enter Mother's Maiden Name   :   ";
cin>>user.MotherMaidenName;
cout<<"Enter Old Password  :   ";
pass();
strcpy(user.UserPassword,match);
mgr.ResetPassword(user);
break;

case 5:
getch();
exit(0);
break;

default:
  cout<<"Wrong Choice.......... ";
}

}//end of while loop

}
}; // end of class




#endif // AUTHMGRGUIH_H_INCLUDED
