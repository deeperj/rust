#include <iostream>
#include <ctime>
#include <vector>

//Start
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int find(int haystack[], int needle, int size);


int main() {
    const int size = 3;
    string animal[size];//array having 3 elements
    animal[0] = "dog";
    animal[1] = "cat";
    animal[2] = "mouse";

    string needle = "duck";
    bool found = false;
    for (int i = 0; i < size; i++) {
        cout << "in animal[" << i << "] address we have " << animal[i] << endl;;
        if (needle == animal[i]) {
            cout << "found " << needle << " at index " << i << endl;
            found = true; // return i
        }
    }if(!found)cout << needle << " not found (-1)" << endl; //return -1
}





int main1(void) {
    cout << "Welcome to the guessing game!" << endl;
    cout << "-----------------------------" << endl;
    //    :input rounds;
    cout << "How many times would you like to play: ";
    int rounds;
    cin >> rounds;
    srand(time(0));  //seed generator
      //cout << "You are playing " << rounds << " times" << endl;
      //:create array to store number of guesses for each round 
    vector<int> rguesses(rounds);
    //: Initialise counter and do rounds loop
    //while (round < rounds) is yes then
    for (int round = 0; round < rounds; round++) {
        cout << "Round " << (round + 1) << " of " << rounds << endl;
        //    : number = generate(betwen 0 and 100); //loop body
        int number = rand() % 100 + 1;
        cout << " generated number = " << number << endl;
        //: prepare non deterministic loop
        bool guessCorrect = false;
        int guesses = 0;  // count the number of guesses
    //while (guessCorrect == false) is yes then
        while (guessCorrect == false)
        {
            //    : display enter the guess ? ;
            cout << "guess a number between 0 and 100: ";
            int guess; //: input guess;
            cin >> guess;
            //check for player exit
            if (guess == -1) { //is yes then
                cout << "Thank you for playing! Have a nice day." << endl;
                return 0;//exit(0);
            }//end if is no
      //if (guess == number) is yes then
      //    : guessCorrect = true;
      //: cout << " Bingo! << endl;
      //else if (guess > number) is yes then
      //    : cout << "it is actually less ";
      //else
      //    :cout << "it is actually greater";
      //end if
      //    :guesses = guesses + 1;
        }//end while is no
    //; rguesses[round] = guesses;
    //; cout << "You Guessed correctly after " << guesses << "guesses")
    }//end while
    return 0;
    ////game summary
    //    :round = 0;
    //: sum = 0;
    //while (round < rounds) is yes
    //    : sum = sum + rguesses[round];
    //: cout << "in round " << round << " you guessed right after " << rguesses[round] << " attempts" << endl;
    //: round = round + 1;
    //end while is no
    //    : cout << " average number of guesses =" << sum / rounds << endl;
}//Stop
