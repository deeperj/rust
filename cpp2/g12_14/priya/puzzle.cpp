#include<iostream>
#include<chrono>
#include "Puzzle.h"
using namespace std;

//------------------------------------------------------------
// test_initializeBoard()

bool Puzzle::test_initializeBoard()
{

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }

    initializeBoard();

    int sum = 8 * 9 / 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            sum-=board[i][j];
        }
    }
    return sum==0;
}

//------------------------------------------------------------
// test_move()

bool Puzzle::test_move()
{
    int v = 1;
    // Leave one place for 8 to move at 2,1 index
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(i==2 && j==1)
                board[i][j] = 0;
            else
                board[i][j] = v++;
        }
    }
    move(8);

    return board[2][1]==8;
}

//------------------------------------------------------------
// test_isWon()

bool Puzzle::test_isWon()
{
    int val = 1;
    // initalize the board with wining order
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(!(i==2 && j==2))
                board[i][j] = val++;;
        }
    }

    return isWon();
}

//------------------------------------------------------------
// default constructor
// initialize the board with 0 and then call initializedBoard

Puzzle::Puzzle()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
    initializeBoard();
}

//------------------------------------------------------------
// initializeBoard()
// initialize the board with random values for puzzle

void Puzzle::initializeBoard()
{

    int i = 0;

    // initialize the board
    do {


        int row = 0, col = 0;	            // to save random indexes
        // Until found empty place for randomly created indexes
        while (board[row][col] != 0) {

            row = rand() % 3;
            col = rand() % 3;
        }
        int num = rand() % 8 + 1;           // generating a random number between 1-8

        // to check if generated number is already stored in Puzzle
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++) {
                if (num == board[k][j])		// if number exist,
                {
                    num = rand() % 8 + 1;	// create again
                    j = -1, k = 0;          // to start over again for new number

                }
            }
        }

        board[row][col] = num;
        i++;
    } while (i < 8);

}


//------------------------------------------------------------
// show()
// show the puzzle board on screen with text format

void Puzzle::show()// to display the Puzzle board
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\t_____________" << endl;
        cout << "\t|";
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                cout << "   |";
            }
            else
                cout << " " << board[i][j] << " |";
        }
        cout << endl;
    }
    cout << "\t_____________" << endl;
}

//------------------------------------------------------------
// move()
// move the entered number on the board if possible

void Puzzle::move(int num)
{
    int row = 0, col = 0;
    for (int i = 0; i < 3; i++)//to find the row of number to be moved
    {
        for (int j = 0; j < 3; j++)//to find the column of number to be moved
        {
            if (board[i][j] == num)
            {
                row = i; col = j;
                break;//once we get the row and column break the loop because we are done
            }
        }
    }

    //next working is to find the free space near the number to be moved
    if (row - 1 >= 0 && board[row - 1][col] == 0)//to check if the number can be moved upward
    {
        board[row - 1][col] = num;
        board[row][col] = 0;
    }
    else if (row + 1 < 3 && board[row + 1][col] == 0)//to check if the number can be moved downward
    {
        board[row + 1][col] = num;
        board[row][col] = 0;
    }
    else if (col - 1 >= 0 && board[row][col - 1] == 0)//to check if the number can be moved left
    {
        board[row][col - 1] = num;
        board[row][col] = 0;
    }
    else if (col + 1 < 3 && board[row][col + 1] == 0)//to check if the number can be moved right
    {
        board[row][col + 1] = num;
        board[row][col] = 0;
    }
    
}


//------------------------------------------------------------
// isWon()
// check if user has solved the puzzle

bool Puzzle::isWon()
{
    //player is won when the numbers 1-8 ar placed in ascending order in the Puzzle board
    int num = 1; 
    bool won = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != num && !(i==2 && j==2))//if atleast one number is not in its place return false
            {
                won = false;
            }
            num++;
        }
    }
    return won;
}


//------------------------------------------------------------
// turn
// show the board and call the move with user input

void Puzzle::turn()
{
    int input;
    this->show();
    cout << "\n Enter the number you want to move :";
    cin >> input;
    this->move(input);
}


//------------------------------------------------------------
// testAllFunctions()
// call all unit tests

void Puzzle::testAllFunctions()
{
    if (test_initializeBoard())
        cout << "initializedBoard() function passed the test.\n";
    else
        cout << "initializedBoard() function failed the test.\n";
    if (test_move())
        cout << "move() function passed the test.\n";
    else
        cout << "move() function failed the test.\n";
    if (test_isWon())
        cout << "isWon() function passed the test.\n";
    else
        cout << "isWon() function failed the test.\n";
    
}

