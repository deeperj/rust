#pragma once
//------------------------------------------------------------------------//
//Implementations and assumption:                                         //
//          - Initialize the board in constructor, call initializeBoard() //
//          - initializeBoard() fill the board with random values         //  
//          - turn() call the show() and then call move() with user input //
//          - move(int) take the input number and move it on the board    //
//          - isWon() check if all number on board are in ordered         //
//------------------------------------------------------------------------//
#include<iostream>
class Puzzle
{
    int board[3][3];                    // board to store puzzle numberss
    bool test_initializeBoard();        // test initializeBoard function
    bool test_move();                   // test move function
    bool test_isWon();                  // test isWon function
    
public:
    Puzzle();                           // default constructor, initialize board
    void initializeBoard();             // initialize board with random numbers
    void show();                        // show board values in a text format
    void move(int num);                 // move the input number to available space
    bool isWon();                       // check if puzzle is solved
    void turn();                        // show the board and call the move
    void testAllFunctions();            // to call the unit tests
};
