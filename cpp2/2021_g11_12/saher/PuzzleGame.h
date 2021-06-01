#ifndef PUZZLE_H
#define PUZZLE_H

#include <stack>
#include <cstdlib>
#include <ctime>
#include "grid.h"
#include <curses.h>
#include <unistd.h>
#include <vector>
#include <queue>


class PuzzleGame
{
    public:
        PuzzleGame();
        ~PuzzleGame();
        void run();

    private:
      grid currState;
      int dim;                  
      std::vector<grid> instructions;     
      int instructionIndex;
      int wRow, wCol;
      enum gameState { PRE_GAME, IN_GAME, POST_GAME, QUIT_GAME };
      gameState state;
      typedef void (PuzzleGame::*menuPtr)();
      menuPtr menu[3];
      void preMenu();
      void ingame();
      void winscreen();
      int posOf(int num, const grid &g);
      bool isGoal(const grid &g);
      typedef bool (PuzzleGame::*canMovePtr)(const grid &g);
      canMovePtr canMove[4];
      bool canMoveUp(const grid &g);
      bool canMoveDown(const grid &g);
      bool canMoveLeft(const grid &g);
      bool canMoveRight(const grid &g);
      typedef void (PuzzleGame::*movePtr)(grid &g);
      movePtr moveGrid[4];
      void moveUp(grid &g);
      void moveDown(grid &g);
      void moveLeft(grid &g);
      void moveRight(grid &g);
      void swap(int i, int z, grid &g);
      void generateRand();
      int inversionCount();
      void decrementInversionCount();
      void print(const grid &g);
      void clearGrid();
      void clearGrid(grid* &root);
};

#endif 