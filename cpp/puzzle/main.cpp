#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main() {
  //declare board array
  const int BSZ=3;
  const int BSZ2=BSZ*BSZ;

  int board[BSZ2]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
  // for(int i=0;i<9;i++)cout << board[i] << endl;
  // return 0;
  //seed random generator
  srand(time(NULL));

  //randomize board
  for(int i=0;i<BSZ2;i++){
    bool fixed=false;
    while(!fixed){
      int fix=rand()%BSZ2;
      if(board[fix]==-1){
        board[fix]=i;
        fixed=true;
      }
    }
  }

  //start game loop
  bool wehaveawinner=false;
  while(!wehaveawinner){
    // print the board
    for(int i=0;i<BSZ;i++){
      for(int j=0;j<BSZ;j++){
        cout << board[i*BSZ+j];
      }cout << endl;
    }
    wehaveawinner=true;
    // ask user to enter value from 0 to 8
    cout << "enter value between 0 and 8: ";
    int v;
    cin >> v;
    //find the index of 0
    int id0=-1;
    for(int i=0;i<BSZ2;i++){
      if(board[i]==0){
        id0=i;
        break;
      }
    }if(id0==-1){
      cout << "error finding 0 index";
    }
    //swap index of 0 with index of value
    board[id0]=board[v];
    board[v]=0;
    //check for winner
    for(int i=0;i<BSZ2;i++){
      if(board[i]!=i){
        wehaveawinner=false;
        break;
      }wehaveawinner=true;
    }
    if(wehaveawinner){
      //printboard one last time
      for(int i=0;i<BSZ;i++){
        for(int j=0;j<BSZ;j++){
          cout << board[i*BSZ+j];
        }cout << endl;
      }
    }
  }
  //
  cout << "we have a winner";
}