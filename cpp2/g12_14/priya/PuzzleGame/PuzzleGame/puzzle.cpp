#include<iostream>
#include "puzzle.h"
using namespace std;

puzzle::puzzle()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
    initializeBoard();
}
void puzzle::initializeBoard()
{

    int i = 0;

    // initialize the board
    do {


        int row = 0, col = 0;	// to save random indexes
        // Until found empty place for randomly created indexes
        while (board[row][col] != 0) {

            row = rand() % 3;
            col = rand() % 3;
        }
        int num = rand() % 8 + 1; // generating a random number between 1-8

        // to check if generated number is already stored in puzzle
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++) {
                if (num == board[k][j])		// if number exist,
                {
                    num = rand() % 8 + 1;	// create again
                    j = -1, k = 0;             // to start over again for new number

                }
            }
        }

        board[row][col] = num;
        i++;
    } while (i < 8);

}

void puzzle::show()// to display the puzzle board
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
void puzzle::move(int num)
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
    else
    {
        //if there is no space near the number print the mesage
        cout << num << "  Cannot move choose again " << endl;
    }
}

bool puzzle::isWon()
{
    //player is won when the numbers 1-8 ar placed in ascending order in the puzzle board
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
void puzzle::turn()
{
    int input;
    this->show();
    cout << "\n Enter the number you want to move :";
    cin >> input;
    this->move(input);
}

