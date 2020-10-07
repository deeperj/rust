#include "atmmm.h"
using namespace std;
int givenPinumber = 5432;



	bool login() {

		cout << " welcome";
		int givenPinNumber = -1;
		bool isPinInvalid = true;

		while (isPinInvalid) {

			cout << "Enter your PIN: ";
			cin >> givenPinNumber;

			if (givenPinNumber == enterpin) {
				isPinInvalid = false;
			}
			else {
				cout << "Invalid PIN number! Try again." << endl;
			}

		}

		return true;

	}
};
class atm {
private:
	char card;
public:
	int getUserOption() {

		int selectedOption = -1;

		cout << "Main menu:" << endl;
		cout << "	1 - View my balance" << endl;
		cout << "	2 - Withdraw cash" << endl;
		cout << "	4 - Exit" << endl;
		cout << "Enter a choice: " << endl;
		cin >> selectedOption;

		return selectedOption;

	}
};
class customer {
public:
	void viewBalance() {
		int balance;

		cout << "You have:" << endl;
		cout << "£100 in your account" << balance << endl;

	}

	void withdrawCash() {

		int selectedOption = -1;
		int valueToWithdraw = 0;
		bool isNotFinished = true;
		int balance;
		cin >> balance;

		do {

			cout << "Withdrawal options:" << endl;
			cout << "1 - $20" << endl;
			cout << "2 - $40" << endl;
			cout << "3 - $60" << endl;
			cout << "4 - $100" << endl;
			cout << "5 - $200" << endl;
			cout << "6 - cancel transaction" << endl;
			cout << "choose a withdrawal option (1-6)" << endl;

			cin >> selectedOption;
			switch (selectedOption) {
			case 1:
				valueToWithdraw = 20;
				break;
			case 2:
				valueToWithdraw = 40;
				break;
			case 3:
				valueToWithdraw = 60;
				break;
			case 4:
				valueToWithdraw = 100;
				break;
			case 5:
				valueToWithdraw = 200;
				break;
			case 6:
				isNotFinished = false;
				break;
			default:
				cout << "Invalid option! Try again." << endl;
				break;
			}

			if (valueToWithdraw != 0) {
				if (valueToWithdraw > balance) {
					cout << "You just have £100" << balance << ". You can't withdraw $" << valueToWithdraw << endl;
				}
				else {
					balance = balance - valueToWithdraw;
					isNotFinished = false;
				}
				valueToWithdraw = 0;
			}

		} while (isNotFinished);

	}
};