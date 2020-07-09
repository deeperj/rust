#include <iostream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //declare board array
    const int BSZ = 3;
    const int BSZ2 = BSZ * BSZ;

    //board pseudo-randomised
    int board[BSZ2] = {1, 4, 2, 6, 0, 5, 7, 3, 8};
    //{0,1,2,3,4,5,6,7,8}
    //seed random generator
    srand(time(NULL));

    //start game loop
    bool wehaveawinner = false;
    while (!wehaveawinner)
    {

        // print the board
        for (int i = 0; i < BSZ; i++)
        {
            for (int j = 0; j < BSZ; j++)
            {
                if (board[i * BSZ + j] == 0)
                    cout << 'X';
                else
                    cout << board[i * BSZ + j];
            }
            cout << endl;
        }

        // ask user to enter value from 0 to 8
        cout << "enter value between 0 and 8: ";
        int v;
        int idv = -1;
        cin >> v;
        //find the index of v
        for (int i = 0; i < BSZ2; i++)
        {
            if (board[i] == v)
            {
                idv = i;
            }
        }
        if (idv == -1)
        {
            cout << "error in input value. Exitting..";
            return 0;
        }
        //find the index of 0
        int id0 = -1;
        for (int i = 0; i < BSZ2; i++)
        {
            if (board[i] == 0)
            {
                id0 = i;
                break;
            }
        }
        if (id0 == -1)
        {
            cout << "error finding 0 index. exitting..";
            return 0;
        }
        //To get value we need to find index

        //swap index of 0 with index of value
        board[id0] = board[idv];
        board[idv] = 0;
        //check for winner
        //check for winner step 1 check first and last board space
        if (
            !((board[0] == 0 || board[0] == 1) && (board[8] == 0 || board[8] == 8)))
        {
            wehaveawinner = false;
            continue;
        }
        //check for winner step 2 check remaining board spaces
        for (int i = 0; i < BSZ2; i++)
        {
            if (i > 0 && i < BSZ2 - 1)
            {
                if ((board[i] != 0 && i > 1 && (board[i - 1] == 0 ? board[i] < board[i - 2] : board[i] < board[i - 1])))
                {
                    // cout << "here" << i << endl;
                    wehaveawinner = false;
                    break;
                }
            }
            wehaveawinner = true;
        }
        if (wehaveawinner)
        {
            //printboard one last time
            for (int i = 0; i < BSZ; i++)
            {
                for (int j = 0; j < BSZ; j++)
                {
                    if (board[i * BSZ + j] == 0)
                        cout << 'X';
                    else
                        cout << board[i * BSZ + j];
                }
                cout << endl;
            }
        }
    }
    //
    cout << "we have a winner";
}