#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <ctime>
#include <conio.h>

using namespace std;

//main account holder class
class accountHolder
{

public:

    //class variables
	int securityPin;
	float accountAmount;
	int numberOfwithDrawnLimit = 3;

	//utility function declaration
	void updateBalance(float amount);

};

// all the files are stored inside in text file
//this function will load all the pins for each account holder
int readPins(accountHolder* AccountHolder)
{
	ifstream fileHandler; //file handler

	fileHandler.open("accounts_pins.txt");//open the files to load the pins

	int securityPin;
	int counter = 0;

	while (fileHandler >> securityPin)
	{
		//assign security pin and amount (the amount is random everytime program is run)
		AccountHolder[counter].securityPin = securityPin;
		AccountHolder[counter].accountAmount = rand() % 101;
		counter++;
	}

	fileHandler.close();
	return counter;
}

//everytime the amoutn is withdrawn this functino updates the amount
void accountHolder::updateBalance(float myAmount)
{
	if (myAmount > 100 || myAmount < 1) cout << "\n Invalid amount\n";
	else if (myAmount > accountAmount) cout << "\nInsufficient balance\n";
	else
	{
		
		accountAmount = accountAmount - myAmount;
		cout << "\nRemaining balance: " << accountAmount << "\n";
	}

	numberOfwithDrawnLimit--;
}


//this function will take the pin from the user and convert into int
int securityPinCheck()
{
	cout << "\nEnter the current security pin for your account:";
	char ch;
	int securityPin;
	int counter;
	string password;
	//we need to hide the pin with esterik so no one can see it
	while ((ch = _getch()) != 13)//until enter keep adding character
	{
		putchar('*');
		password += ch;
	}

	//convert password from string to integer 
	securityPin = atoi(password.c_str());

	return securityPin;
}

//this function will check if the pin is valid or not
int validateSecurityPin(int intSecurityPin, accountHolder* arrayofAccountHolder, int counter)
{
	for (int indexCounter = 0; indexCounter < counter; indexCounter++)
	{
		//check if the pin matches accounts pin
		if (arrayofAccountHolder[indexCounter].securityPin == intSecurityPin)
			return indexCounter;//if matched return the index
	}

	return -1;//otherwise return -1
}

int main()
{
	//for random function we need to give a seed
	srand(time(0));
	accountHolder atmUsers[50];
	int counter;
	int securityPin;

	//load pins
	counter = readPins(atmUsers);

	char userEnteredInput = ' ';//declare user input as empty
		
	while (userEnteredInput != '3') // keep running the menu until user exists the program
	{
		cout << "1: Check Balance or Withdraw\n";
		cout << "2: Change your Pin\n";
		cout << "3: Exit the program\n";

		cout << "** Enter number 1-3 and press enter **: \n";

		cin >> userEnteredInput;

		switch (userEnteredInput)
		{
		case '1':
		{
			securityPin = securityPinCheck();
			int i = validateSecurityPin(securityPin, atmUsers, counter);
			float amount;
			//check if securityPin exists
			if (i != -1)
			{
				//check if 3 withdrawals have been made
				if (atmUsers[i].numberOfwithDrawnLimit > 0)
				{
					cout << "\nYour current balance is: "; cout << atmUsers[i].accountAmount;
					cout << "\nEnter amount to withdraw: ";
					cin >> amount;
					atmUsers[i].updateBalance(amount);
				}
				else
				{
					cout << "Withdrawal limit reached - you can't withdraw more than 3 times in 5 minutes\n";
				}
			}
			else
			{
				cout << "\nInvalid Pin Entered!!\n";
			}
		}
		break;
		case '2':
		{

			//cout << "Enter your current security pin: ";
			securityPin = securityPinCheck();
			int i = validateSecurityPin(securityPin, atmUsers, counter);

			//check if securityPin exists
			if (i != -1)
			{
				cout << "\nEnter your new security pin: ";
				cin >> securityPin;
				//change securityPin
				atmUsers[i].securityPin = securityPin;
				cout << "\nyour security pin has changed successfully\n";

				//update to file
				ofstream fileHandler;
				fileHandler.open("accounts_pins.txt");

				for (int j = 0; j < counter; j++) fileHandler << atmUsers[j].securityPin << endl;

				//close file
				fileHandler.close();
			}
		}
		break;
		case '3':
			cout << "\nYou have exit the program successfully";
			break;
		default:
			cout << "\nPlease enter the correct option\n";
			break;
		}
	}

	return 0;
}

