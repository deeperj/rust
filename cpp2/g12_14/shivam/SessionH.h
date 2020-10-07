#ifndef SESSIONH_H_INCLUDED
#define SESSIONH_H_INCLUDED

// Header File included
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<conio.h>

using namespace std;


// class implementation
class Session
{
private:
	Details user;
	Status status;
	Details validUsers[50];
	Error errors;
public:
	Status getStatus()
	{
	return(status);
	}

	void setStatus(Status status1)
	{
	status=status1;
	}

		void ValidatePassword(Details user)
	{
	    if(strlen(user.UserPassword)<6)
        {

            cout<<"Password must be greater than 6 characters";
        }

	}

	void ValidateUser()
	{
	Details user1;
	 ifstream fin;
	 int flag=0;
	 fin.open("Auth",ios::in|ios::binary);
	 if(fin==NULL)
	 {
	  cout<<"can't open file ";
	  getch();
	  exit(0);
	 }
	 while(fin.read((char*)&user1,sizeof(user1))!=NULL)
	 {
	  if(strcmp(user1.UserEmail,user.UserEmail)==0 && strcmp(user1.UserPassword,user.UserPassword)==0)
	  {
	  flag=1;
	  break;
	  }
	 }
	 if(flag==1)
	 {

	   status.setStatus(1);
	   status.setMessage("Login Successful.....");
	   setStatus(status);
	   status=getStatus();
	   cout<<endl<<status.getMessage();
	 }
	   else
	   {
	   errors.setError(0);
	   errors.setMessage("Login Failed..........");
	   errors=getError();
	   cout<<endl<<errors.getMessage();
	   }
	   fin.close();

	}

	void setUser(Details user1)
	{
	user=user1;
	}

	void createUser(Details user)
	{
	ofstream fout;
	Details user1;
	int flag=0;
	fout.open("Auth",ios::app|ios::binary);
	if(fout==NULL)
	{
	  cout<<"can't open file ";
	  getch();
	  exit(0);
	}

	ifstream fin;
	fin.open("Auth",ios::in|ios::binary);

	while(fin.read((char*)&user1,sizeof(user1))!=NULL)
	{
	    if(strcmp(user1.UserEmail,user.UserEmail)==0)
        {
            cout<<"Duplicate Email id ";

            flag=1;
            break;
        }

	}

	if(flag==0)
    {

    fout.write((char*)&user,sizeof(user));
	cout<<endl<<"User Registred Successfully";
	fout.close();
    }
	}

	Error getError()
	{
	return(errors);
	}

	void setError(Error error1)
	{
	errors=error1;
	}
}; // end of Session class


#endif // SESSIONH_H_INCLUDED
