#ifndef MANAGERH_H_INCLUDED
#define MANAGERH_H_INCLUDED

// Header File included
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<conio.h>


using namespace std;

//global declaration
char match1[20];

// function to enter password
void pass1()
  {
    int i,x;
    char ch='/0';
    for(i=0;i>=0;)
     {
       ch=getch();

      if(ch!=8&&ch!=13)
        {
         cout<<"*";
         match1[i]=ch;
         i++;
        }
      else if (ch==8) // if backspace is presssed
       {
         cout<<"\b \b"; // moves cursor to the left print <space> again move cursor to left
         i--;
       }
      else if(ch==13)
    {
         match1[i]='\0'; // if enter is pressed, last character in match[] becomes null
        break;         // for end of string
    }
    else
    {
         break;
    }
  }

}

// class implementation
class Manager
{
private:
	//AuthMgrGui gui;
	Session session;
public:
	void login(Details user)
	{
	session.setUser(user);
	session.ValidateUser();
	}

	void Register(Details user)
	{
	session.setUser(user);
	session.createUser(user);
	}

	void requestReset(Details user)
	{
	 ifstream fin;
	 Details user1;
	 int flag=0;
	 fin.open("Auth",ios::in|ios::binary);
	 if(fin==NULL)
	 {
	   cout<<"can't open file";
	   getch();
	   exit(0);
	 }

	 while(fin.read((char*)&user1,sizeof(user1))!=NULL)
	 {
	 if(strcmp(user1.UserEmail,user.UserEmail)==0 && strcmp(user1.MotherMaidenName,user.MotherMaidenName)==0)
	 {
	 flag=1;
	 break;
	 }
	 }
	 if(flag==1)
	 {
	  cout<<endl<<"Request Successful, Password retrieved  :   "<<user1.UserPassword;
	 }
	 else
	   cout<<endl<<"Invalid Detail..........";

	 fin.close();
	}

	void ResetPassword(Details user)
	{
	 fstream fio;
	 Details user1;
	 int flag=0;
	 char newpswd[100],cpswd[100];
	 int loc=0;

	 fio.open("Auth",ios::in|ios::out|ios::binary);
	 if(fio==NULL)
	 {
	   cout<<"can't open file";
	   getch();
	   exit(0);
	 }

	 while(fio.read((char*)&user1,sizeof(user1))!=NULL)
	 {
	 if(strcmp(user1.UserEmail,user.UserEmail)==0 && strcmp(user1.UserPassword,user.UserPassword)==0)
	 {
	 flag=1;
	 break;
	 }
	 loc+=sizeof(user1);
	 }

	 if(flag==1)
	 {
	 cout<<endl<<"Enter New Password   :    ";
	 pass1();
     strcpy(newpswd,match1);

	 cout<<endl<<"Confirm Password     :     ";
	 pass1();
     strcpy(cpswd,match1);


	  if(strcmp(newpswd,cpswd)==0)
	  {
	  strcpy(user1.UserPassword,newpswd);
	  fio.seekp(loc);
	  fio.write((char*)&user1,sizeof(user1));
	  cout<<endl<<"Password changed successfully....";
	  }
	  else
	  cout<<endl<<"Password and confirmed password do not match";
	 }
	 else
	 {
	   cout<<endl<<"Invalid Details.......";
	 }
	 fio.close();
	}
}; //end of Manager class


#endif // MANAGERH_H_INCLUDED
