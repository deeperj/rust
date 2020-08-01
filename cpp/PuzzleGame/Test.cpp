
#include "Test.h"
#include "PuzzleGame.hpp"
#include "expect.h"

Test::Test() {
	game = new PuzzleGame();
    ok = false;
}
Test::~Test() {
	delete game;
}
int test_find(int sv) {
	Test t;
	return t.TestFind(sv);
}
int Test::TestFind(int v) {
    return game->find(v);
}
bool test_choiceValid(int sv) {
    Test t;
    return t.TestChoiceValid(sv);
}
bool Test::TestChoiceValid(int c) {
    game->choice = c;
    return game->choiceValid();
}
void Test::testall() {
    describe("PuzzleGame Tests**", [] {
        describe("1. PuzzleGame::find() takes search value returns an index or -1", [] {
            it("find() should return the index of 4", [] {
                expect(test_find(0)).toBe(4);
            });
            it("find() should return -1 for 'c'", [] {
                expect(test_find('c')).toBe(-1);
            });
        });
        describe("2. PuzzleGame::choiceValid() returns bool based on if choice is valid", [] {
            it("choiceValid() should return true for choice='4'", [] {
                expect(test_choiceValid('4')).toBe(true);
            });
            it("choiceValid() should return false for choice='d'", [] {
                expect(test_choiceValid('d')).toBe(false);
            });
        });
    });
    testSummary();

}
