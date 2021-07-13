
#include "test.h"
#include "expect.h"

void runtests() {
    describe("PuzzleGame Tests**", [] {
        describe("1. PuzzleGame::find() takes search value returns an index or -1", [] {
            //Arrange
            int haystack[4]={0,1,2,3};
            int needle = 2;
            int size = sizeof(haystack)/sizeof(haystack[0]);
            PuzzleGame game;
            //Act 
            int result = game.find(haystack,needle,size);
            //assert
            it("find() should return the index of 2", [result] {
                expect(result).toBe(2);
            });
            it("find() should return -1 for 'c'", [] {
                //expect(test_find('c')).toBe(-1);
            });
        });
        describe("2. PuzzleGame::choiceValid() returns bool based on if choice is valid", [] {
            it("choiceValid() should return true for choice='4'", [] {
                //expect(test_choiceValid('4')).toBe(true);
            });
            it("choiceValid() should return false for choice='d'", [] {
                //expect(test_choiceValid('d')).toBe(false);
            });
        });
    });
    testSummary();
}
