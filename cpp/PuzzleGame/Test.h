#pragma once
#include <assert.h>
//class AsserErr {};

class PuzzleGame;

class Test {
public:
	void testall();
	int TestFind(int);
	bool TestChoiceValid(int c);
	bool getOk();
	Test();
	~Test();
private:
	bool ok;
	PuzzleGame* game;
};