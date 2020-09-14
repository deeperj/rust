
#include <stdio.h>
float balance = 0; // supoose initial balance for everyone shuld be zero before the any uses
int anotherTransaction;
void transaction(){
int choice;
printf("enter the one any options ");
printf("withdarw");
printf(" Deposit");
printf(" Balance");
scanf("%d", &choice);

switch(choice){
case 1:

int amountToWidthdraw;
printf("Please enter amount to withdraw: ");
scanf("%d", &amountToWidthdraw);
if(amountToWidthdraw > balance){
printf("There is no insuffient funds in your account");

printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n");
scanf("%d", &anotherTransaction);
if(anotherTransaction == 1){

transaction();
}
} else {

balance = balance - amountToWidthdraw;

printf("You have withdrawn %d and your new balance is %f ", amountToWidthdraw, balance);


printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n");
scanf("%d", &anotherTransaction);
if(anotherTransaction == 1){

transaction();
}


}
break;




case 2:

// BALANCE
printf("Your bank balance is: %f", balance);

// request for another transaction
printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n");
scanf("%d", &anotherTransaction);
if(anotherTransaction == 1){
// call our transaction method here
transaction();
}

break;
}

}
int main(){


// This is our ATM machines, we are here for your help, select any options for cash to withdraw or pin services.

transaction();

return 0;
}