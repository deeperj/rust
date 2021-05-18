#include"Puzzlegame.h"
#include"ctime"

void Puzzlegame :: randomizeboard()
{
    srand (time(NULL));

    for(int i = 0 ; i<BSZ2; i++)
    {

        board[i] = -1;
    }
    for(int i=0; i<BSZ2; i++){
        bool fixed = false;
        while (fixed == false){
            int fix = rand ()%BSZ2;
            if ( board[fix] == -1){
                board[fix] = i;
                fixed = true;
            }
        }
    }
}

void Puzzlegame :: displayBoard(){
    for(int i=0; i<BSZ; i++){
        for(int j=0; j<BSZ; j++){
            cout << board[i*BSZ+j] <<" ";
        }
        cout << endl;
    }
}

void Puzzlegame :: getchoice(){
    cout << "Enter Choice: ";
    char v;
    cin >> v;
    choice = v;

}

bool Puzzlegame :: checkChoice(){
    choice = choice - '0';
    int v = choice;

    if(v<=0 || v > 8){
        return false;

    }
    for(int i=0; i<BSZ2; i++){
        if (board[i]==v){
            idv=i;

        }
    }
    for(int j=0; j<BSZ2; j++){
        if(board[j ==0]){
            id0 = j;
        }
    }
    int temp;
    temp = idv - id0;
    if((temp==-3)||(temp==3)||(temp==-1)||(temp==1)){
        return true;

    }
    else{
        return false;

    }
}

void Puzzlegame :: swapPiece(){
    board[id0]=choice;
    board[idv]=0;

}

void Puzzlegame :: checkwin(){
    if(board[0]!=1 && board[8]!=0)
    {

        winner = false;
        return;

    }
    for (int i=1; i<BSZ2-1; i++)
    {
        if(!(board[i]>board[i-1])){
            winner = false;
            return;

        }

    }
    winner = true;
    return;
}

void Puzzlegame :: startgame(){
    cout << "/t/t/t/ Welcome To The Puzzle Game" << endl;
    randomizeboard();
    while (winner ==false)
    {

        displayBoard();
        bool choicecorrect;
        choicecorrect = false;

        while(choicecorrect == false){
            getchoice();
            choicecorrect = checkChoice();

        }
        swapPiece();
        checkwin();

    }
    if(winner == true)
    {

        displayBoard();
        cout << "Congratulations You Win";
    }
}
