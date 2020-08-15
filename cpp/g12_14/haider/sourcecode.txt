#include <iostream>
#include <cstdlib>
#include <ctime>
using std::time;
using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;

const int arrayAmount = 3;

int a[arrayAmount][arrayAmount] =
{
{1,2,3},
{4,5,6},
{7,8,0}
};

int b[arrayAmount][arrayAmount] =
{
{1,2,3},
{4,5,6},
{7,8,0}
};
class puzzle {
private:
	
	

	int i = 2; // row Position
	int j = 2; // column Position
public:
	void moveUp()
	{
		int vP = i;
		if (vP + 1 < 3 && vP >= 0) {

			a[i][j] = a[i + 1][j];
			a[i + 1][j] = 0;
			i += 1;
		}
	}
	void moveDown()
	{
		int vP = i;
		if (vP + 1 <= 3 && vP > 0) {

			a[i][j] = a[i - 1][j];
			a[i - 1][j] = 0;
			i -= 1;
		}
	}
	void moveRight()
	{
		int hP = j;
		if (hP + 1 <= 3 && hP > 0) {

			a[i][j] = a[i][j - 1];
			a[i][j - 1] = 0;
			j -= 1;
		}
	}
	void moveLeft()
	{
		int hP = j;
		if (hP + 1 < 3 && hP >= 0) {

			a[i][j] = a[i][j + 1];
			a[i][j + 1] = 0;
			j += 1;
		}
	}
	int solved()
	{
		int correct;

		for (int i = 0; i < arrayAmount; i++) {
			for (int j = 0; j < arrayAmount; j++) {
				if (a[i][j] == b[i][j])
					correct = 1;
				else
					return -1;
			}
		}
		return 1;
	}
	void change()
	{
		for (int i = 0; i < 100000; i++)
		{
			const int a = (rand() % 4);
			switch (a)
			{
			case 0:
				moveUp();
				break;

			case 1:
				moveDown();
				break;

			case 2:
				moveRight();

				break;

			case 3:
				moveLeft();
				break;
			}
		}
	}
	void Board() {
		for (int i = 0; i < arrayAmount; i++) {
			for (int j = 0; j < arrayAmount; j++)
				cout << "  " << a[i][j];
			cout << endl << endl;
		}
	}
};



int main()
{
	puzzle g;
	g.change();
	if (g.solved() == -1)
	{
		bool quit(false);

		do
		{
			g.Board();

			char a;
			cout << "w - Up, s - Down, a - Left, d - Right" << endl;
			cin >> a;
			switch (a)
			{
			case 'S':
			case 's':
				g.moveUp();
				break;

			case 'W':
			case 'w':
				g.moveDown();
				break;

			case 'A':
			case 'a':
				g.moveRight();

				break;

			case 'D':
			case 'd':
				g.moveLeft();
				break;

			default:
				cout << "Wrong" << endl;
				break;

			}

			if (g.solved() == 1) {
				cout << "Solved." << endl;

				quit = true;
			}
			system("cls");
		} while (quit == false);
	}
	else
		for (int i = 0; i < arrayAmount; i++) {
			for (int j = 0; j < arrayAmount; j++)
				cout << "  " << a[i][j];
			cout << endl << endl;
		}
	cout << "You win";


	return 0;
}
