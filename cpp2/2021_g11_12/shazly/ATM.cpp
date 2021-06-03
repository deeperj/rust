#include "ATM.h"

void user ::  setname(string Name) 
{
  name = Name;
}

string user :: getname()
{
  fstream bank;
  bank.open("bank.txt");
  bank>>pin>>name>>balance;
  return name;
}

void user :: setpin(string Pin)
{
  string name ,pin;
  int balance;
  fstream bank;
  bank.open("bank.txt");
  bank>>pin>>name>>balance;
  bank.close();
  std::ofstream ofs("bank.txt", std::ofstream::trunc);
  ofs<<Pin<<" "<<name<<" "<<balance;
  ofs.close();
  
}

string user :: getpin()
{
  fstream bank;
  bank.open("bank.txt");
  bank>>pin>>name>>balance;
  return pin;
}

void user :: setbalance(int Balance)
{
  balance=Balance;
}

int user :: getbalance()
{
  fstream bank;
  bank.open("bank.txt");
  bank>>pin>>name>>balance;
  return balance;
}

bool user :: verifypin(string Pin)
{
  if (Pin == getpin())
    {
      cout<<"Authenticated successfully"<<endl;
      cout<<"Welcome "<<name<<endl;;
      return true;
    }
  else
    {
      cout<<"The pin you entered is not correct"<<endl;
      return false;
    }
}

void user :: userban()
{
  string name ,pin;
  int balance;
  fstream bank;
  bank.open("bank.txt");
  bank>>pin>>name>>balance;
  pin= pin+"//";
  bank.close();
  std::ofstream ofs("bank.txt", std::ofstream::trunc);
  ofs<<pin<<" "<<name<<" "<<balance;
  ofs.close();
}

void user :: withdraw()
{
  int currentbalance=0;
  currentbalance=getbalance();
  cout<<"How much do you want to withdraw?"<<endl;
  cout<<"current balance = £"<<getbalance()<<endl;;
  int amount,upperlimit=500, lowerlimit=20;
  static int withcount=0;
  cin>>amount;
  if (amount<=0)
  {
    if(amount==-1)
    {
      menu();
    }
    else
    {
      cout<<"REQUEST UNSUCCESSFUL"<<endl;
    }
  }
  bool verify = false;
  while (verify==false)
  {
    if (amount>currentbalance)
    {
      cout<<"The amount is more than your balance."<<endl;
      cout<<"Please enter a valid amount or (-1) to exit: "<<endl;
      cin>>amount;
      if (amount==-1)
      {
        verify=true;
        break;
      }
    }
    else if (amount==0&&currentbalance==0)
    {
      cout<<"Please enter a valid amount or (-1) to go exit:"<<endl;
      cin>>amount;
      if (amount==-1)
      {
        verify=true;
        break;
      }
    }
    else if (amount<=0)
    {
      cout<<"Please enter a valid amount or (-1) to go exit:"<<endl;
      cin>>amount;
      if (amount==-1)
      {
        verify=true;
        break;
      }

    }
    else if (amount>upperlimit)
    {
      cout<<"You cannot withdraw more than £500"<<endl;
      cin>>amount;
      if (amount==-1)
      {
        verify=true;
        break;
      }
    }
    else if (amount<lowerlimit)
    {
      cout<<"You Cannot Withdraw Less Than £20"<<endl;
      cin>>amount;
      if (amount==-1)
      {
        verify=true;
        break;
      }
    }
    else
    {
      cout<<"Are you sure you want to withdraw £"<<amount<<" ?"<<endl;
      cout<<"Y/N"<<endl;
      char sure;
      cin>>sure;
      if (sure=='Y'||sure=='y')
      {
        while (withcount<3)
        {  
          cout<<"An Amount Of £"<<amount<<" Has Been Withdrawn From Your Account."<<endl;
          cout<<"Your Current Balance = £"<<currentbalance-amount<<endl;
          int newbalance;
          string name ,pin;
          int balance;
          fstream bank;
          bank.open("bank.txt");
          bank>>pin>>name>>balance;
          bank.close();
          std::ofstream ofs("bank.txt", std::ofstream::trunc);
          newbalance=balance-amount;
          ofs<<pin<<" "<<name<<" "<<newbalance;
          ofs.close();
          verify=true;
          break;
        }
        withcount++;
        if (withcount>3)
        {
          cout<<"You Cannot Withdraw More Than 3 times In The Same Session."<<endl;
          verify=true;
        }
      }
      else if (sure=='n'||sure=='N')
      {
        verify=true;
      }
    }
  }

}

bool user :: isNumber(const string& str)
{
  for (char const &c : str) 
  {
    if (isdigit(c) == 0) return false;
  }
return true;
}

void user :: changePin()
{
  cout<<"Please Enter Your New Pin"<<endl;
  string _pin;
  string newpin;
  bool OkPin=false;
  cin>>_pin;
  while (OkPin==false)
  {
    if (_pin=="-1")
    {
      menu();
      break;
    }
    while (_pin==getpin())
    {
      cout<<"Your New PIN Can Not Be The Same As Your Old PIN."<<endl;
      cout<<"Please Enter A Different PIN: "<<endl;
      cin>>_pin;
      OkPin=false;
    }
    while (_pin.length()!=4)
    {
      cout<<"Your PIN Must Consist Of Four Digits:"<<endl;
      cin>>_pin;
      OkPin=false;
    }
    while (!isNumber(_pin))
    {
      cout<<"Your PIN Must Only Consist Of Numbers: "<<endl;
      cin>>_pin;
      OkPin=false;
    }
    setpin(_pin);
    newpin = getpin();
    cout<<"Your PIN Has Been Changed Succesfully"<<endl;
    OkPin=true;
  }
}

void user :: DisplayBalance()
{
  int currentbalance;
  currentbalance=getbalance();
  cout<<"Your Current Balance Is = £"<<currentbalance<<endl;
}

void user :: menu()
{
  int choice,x=1;
  cout<<"How can we help you? \n1-View Balance \n2-Change PIN\n3-Withdraw\nPress (0) To Exit"<<endl;
  cin>> choice;
  if(choice == 1)
  {
    DisplayBalance();
  }
  else if(choice==2)
  {
    changePin();
  }
  else if (choice==3)
  {
    withdraw();
  }
  else if (choice==0)
  {
    cout<<"Please Take Your Card From The Machine."<<endl;
    cout<<"Thank you for using our Bank."<<endl;
    exit(0);
  }
  else 
  {
    cout<<"Please enter a valid number: "<<endl;
    menu();
  }
}
void user :: startSession()
{
  bool auth = false;
  string checker;
  char insert;
  fstream bank;
  bank.open("bank.txt");
  bank>>checker;
  cout<<"Please insert your card in the machine and press any key to Continue."<<endl;
  cin>>insert;
  cout<<"Card read succesfully."<<endl;
  for (int i=0;i<=3;i++)
  {
    if (checker.size() > 4)
    {
      cout<<"This Account Is Banned Please Call Your Bank"<<endl;
      break;
    }
    
    if( i >= 3 )
    {
      userban();
      cout<<"THIS SESSION IS TEMPORARILY BANNED, TRY AGAIN LATER"<<endl;

      auth = false;
      break;
    }
      
    cout<<"Please enter your pin:"<<endl;
    string newpin;
    cin>>newpin;
    auth=verifypin(newpin);
    if (auth==true)
      {
        break;
      }
  }
    char x;
    while (x!='0')
    {
      if (auth==true)
      { 
        menu();
        cout<<"Press any key to go back to tha main menu or (0) to exit."<<endl;
        cin>>x;
      }
    }
    cout<<"Please Take Your Card From The Machine."<<endl;
    cout<<"Thank you for using our Bank."<<endl;
}
     


