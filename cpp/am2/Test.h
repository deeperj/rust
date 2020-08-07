#ifndef TEST_H
#define TEST_H
#include "managerUI.h"
#include <assert.h>

using std::cout;
using std::endl;
using std::string;

//  typedef void (Test::*Spec1)(); //= &Target1::Method;
//  (target.*oneParam)(1);
// typedef void (*Spec2)(int);

class AssertErr {};

class Test {
private:
	Amtui ui;
	bool ok;
public:
	int id(int t);
	void testuifid_conf();
	void testuifid();
	void testcycleback();
	void testcycleback2();
	void testLogin();
	void testLogin2();
	void testVerifyLogin();
	void testVerifyLogin2();
	void testVerifyPasswordLength();
	void testVerifyPasswordLength2();
	void testall();
	bool getOk();
};

#endif


