#include "managerUI.h"
#include "Test.h"
int main() {
	//int main1(int argc, char **argv) {
	// initialise
	// setup memory and clear screen
	bool runtests = false;
	if (!runtests) {
		Amtui ui;
		ui.run();
	}
	else {
		Test t;
		t.testall();
	}
	return 0;
}

