#include <iostream>
#include <ctime>
#include<string>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#include "ctime"

//Puzzlegame.h
const int BSZ=3;
const int BSZ2=BSZ*BSZ;
class Puzzlegame{
int choice,idv,id0,find;
bool winner, choicecorrect;
private:
bool checkChoice();
void randomizeboard();
void swapPiece();
void checkwin();
void getchoice();
void displayBoard();
void displaywinner();
public:
void startgame();
int board[BSZ2]={0,1,2,3,4,5,6,7,8};
};

void Puzzlegame :: randomizeboard()
{
srand (time (NULL));
for (int i=0; i<BSZ2; i++){
board[i] = -1 ;
}
for (int i=0; i<BSZ2; i++){
bool fixed = false;
while (fixed == false){
int fix = rand ()%BSZ2;
if (board [ fix] == -1) {
board [ fix] = i;
fixed = true;
}
}
}
}
void Puzzlegame :: displayBoard() {
for (int i=0; i<BSZ; i++){
for (int j=0; j<BSZ; j++){
cout << board [i*BSZ+j]<<" ";
}
cout << endl;
}
}
void Puzzlegame :: getchoice() {
char v;
cout <<"Enter choice";
cin >> v;
choice = v;
}
bool Puzzlegame :: checkChoice() {
choice = choice-'0';
int v = choice;
if (v<=0 || v>8){
return false;
}
for (int i=0; i<BSZ2; i++){
if (board[i]==v){
idv=i;
}
}
for (int j=0; j<BSZ2; j++){
if (board[j]==0){
id0=j;
}
}
int temp;
temp = idv - id0;
if ( (temp==-3) || (temp==3) || (temp==-1) || (temp==1)){
return true;
}
else {
return false;
}
}
void Puzzlegame :: swapPiece() {
board [id0]=choice;
board[idv]=0;
}
void Puzzlegame :: checkwin() {
if (board[0]!=1 && board[8]!=0) {
winner = false;
return;
}
for (int i=0; i<BSZ2-1; i++){
if(!(board[i]>board[i-1])){
winner = false;
return;
}
}
winner = true;
return;
}
void Puzzlegame :: startgame(){
cout << "Welcome to Puzzle Game"<<endl;
randomizeboard();
while (winner == false) {
displayBoard();
bool choicecorrect;
choicecorrect = false;
while (choicecorrect == false) {
getchoice();
choicecorrect = checkChoice();
}
swapPiece();
checkwin();
}
if (winner==true){
displayBoard();
cout<<"Congrats! You Won"<<endl;
}
}

int main()
{
Puzzlegame noPuzzle;
noPuzzle.startgame();
return 0;
}