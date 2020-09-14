#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main() {
  //declare board array
  const int BSZ=3;
  const int BSZ2=BSZ*BSZ;
  const int MAXV=5; //maximum number of moves + 1 for length
  int movecount=0;
  int board[BSZ2]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
  int validMoves[BSZ2][MAXV]=
  {
    2,1,3,-1,-1,
    3,0,2,4,-1,
    2,1,5,-1,-1,
    3,0,4,6,-1,
    4,1,3,5,7,
    3,2,4,8,-1,
    2,3,7,-1,-1,
    3,6,8,4,-1,
    2,5,7,-1,-1
  };
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
    //cin >> v;
    v=validMoves[id0][1+(rand()%validMoves[id0][0])];
    cout << v << endl;
    movecount++;
    //swap index of 0 with index of value
    board[id0]=board[v];
    board[v]=0;
    //check for winner step 1 check first and last board space
    if(
        !((board[0]==0 ||board[0]==1)
        &&(board[8]==0 ||board[8]==8))
      )
    {
      wehaveawinner=false;
      continue;
    }
    //check for winner step 2 check remaining board spaces
    for(int i=0;i<BSZ2;i++){
      if(i>0 && i<BSZ2-1){
        if( board[i]!=0 
            && i>1 && (board[i-1]==0?
            board[i]<board[i-2]:
            board[i]<board[i-1])
          )
        {
          wehaveawinner=false;
          break;
        }
      }
      wehaveawinner=true;
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
  cout << "we have a winner after " << movecount << " moves.";
}