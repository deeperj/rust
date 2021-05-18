#include <iostream>

using std::string;

using std::cout;

using std::cin;

using std::endl;

string d2b(int N)
{
    string st = "";

    while (N != 0)
    {
        int R = N % 2;

        if (R == 0)
        {
            st = "0" + st;
        }
        else
        {
            st = "1" + st;
        }
        N = N / 2;
    }
}

int main()
{
    int N;

    cout << "enter a value";

    cin >> N;

    cout << "binary equivalent is :" << d2b(N) << endl;
}