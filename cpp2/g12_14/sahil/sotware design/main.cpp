#include"iostream"
#include"atmmm.h"
using namespace std;
int main() {
	cout << "              Welcome to ATM    ";

	cout << "      insert your card            " << endl;

	cout << " please press 1 to continue.......";
	int b;
	cin >> b;
	cout << "   please enter your pin  ";

	customer task;
	task.enterpin();
	task.enteramount();
	atm task;
	task.getUserOpt();
}



