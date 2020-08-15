#include<iostream>
using namespace std;
int main(){


    class pinnumber{
        public:

 //card is input in the system

int pinnumber1;//pin number 1 is the real pin number given by bank 

 int pinnumber2;//pin number 2 is the enter pin number in machine and this value was displayed as *.
 
if(pinnumber2==pinnumber1){
    cout<<"select option to processed"<<endl;//when the enter pin number is correct ,system goes to display other options.
}

else{
    cout<<"re-enter the pin or log out "<<endl;
}

//that means when  the pin number is not correct ,you need to again enter the right pin or take your card and stop the process.


}