
#include <iostream>

using namespace std;
class staff
{
  private:
  char staffName[20];//var to staff Name
  long int staffsalary;//var to staff data
  public:
  void getData();//function to collect staff data
  void displayData();//function to displacy staff data
};//class complete

void staff:: getData() //declaring body of function outside class.
{
cout <<"Enter the staff name :";
cin >> staffName;  //accepting value for vars
cout<<endl<<"enter staff  salary:";
cin>>staffsalary; // accepting value for var 
cout<<endl<<"---------------------"<<endl; //decoration :-)
}

void staff::displayData()//function body outside class i.e outlibne func.{
 { cout<<"staff name:"<<staffName<<endl;
  cout<<"staff salary:"<<staffsalary<<endl;
  cout<<"--------------------------"<<endl;
  }

  int main()
  {
   staff e[10]; //declaring array of object of size 10 i.e 10 objects.
   int i;
   //clrscr//clears the screen
   //we will cal function  for each object though for loop fpr (i=1;<4;i++)
   for (i=0;i<4;i++)
    {
   // here we will call this function for 3 times.
   e[i].getData();
    }
   //again using for loop to call display function
   for (i=0; i<4; i++)
    {
     e[i].displayData(); //calling displayData function
    }
  //getch()

  return 0;
  }

