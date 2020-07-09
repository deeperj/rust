import 'dart:math';
import 'dart:io';
import 'dart:convert';

class TicTacToeGame {

  final _random = new Random();
  bool winner=false;
  final List validMoves = const [
    [1,3],
    [0,2,4],
    [1,5],
    [0,4,6],
    [1,3,5,7],
    [2,4,8],
    [3,7],
    [6,8,4],
    [5,7]
  ];
  // List gameState = [-1,-1,-1,-1,-1,-1,-1,-1,-1];
  final int _bsz=3;
  final int _bsz2=9;
  int vdx,zdx,_c;
  List board = [1,4,2,6,0,5,7,3,8];
  
  void drawBoard(){
    var sb=new StringBuffer();
    for(var i=0;i<_bsz;i++){
      for(var j=0;j<_bsz;j++)
        if (board[i * _bsz + j] == 0)
          sb.write("X");
        else
          sb.write(board[i * _bsz + j]);
      print(sb);
      sb.clear();
    }
  }

  static void gameLoop(){
    new TicTacToeGame().loop();
  }
  void loop(){
    while(!winner){
      drawBoard();
      _c= getChoice();
      zdx=find(board,0);
      vdx=find(board,_c);
//      print(validMoves[zdx]);
      if(_c==-1 || !validChoice()){
        print("invalid choice");
        continue;
      }
      swapPieces();
      winner=checkWinner();
      if(winner){
        drawBoard();
        print("we have a winner!");
      }
    }
  }
  void swapPieces(){
    board[zdx]=board[vdx];
    board[vdx]=0;
  }
  bool validChoice(){
    return validMoves[zdx].contains(vdx);
  }
  int getChoice(){
    stdout.write("select a value: ");
    var line =stdin.readLineSync(encoding: Encoding.getByName('utf-8'));
    try{
       return int.parse(line.trim());    
    } on Exception{
      return -1;
    }
  }
  int find(List a,int search){
    for(var i=0;i<a.length;i++){
      if(a[i]==search)
        return i;
    }
    return -1;
  }
  void gamePlay(){
    
  }
  bool checkWinner(){
    if (
      !((board[0] == 0 || board[0] == 1) && (board[_bsz2-1] == 0 || board[_bsz2-1] == 8)))
    {
      return false;
    }
    //check for winner step 2 check remaining board spaces
    for (int i = 0; i < _bsz2; i++)
    {
      if (i > 0 && i < _bsz2 - 1)
      {
        if ((board[i] != 0 && i > 1 && (board[i - 1] == 0 ? board[i] < board[i - 2] : board[i] < board[i - 1])))
        {
          // cout << "here" << i << endl;
          return false;
        }
      }
    }
    return true;
  }
}

void main() {

//   1. gameLoop();
//   2. drawBoard(); done
//   3. getChoice();
//   4. validChoice();
//   5. checkWinner();
//   6. randomizeBoard(); done
//   7. swapPiece();
 TicTacToeGame.gameLoop();
}
