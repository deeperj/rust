
import 'package:flutter/material.dart';
import 'package:puzzle/TicTacToeGame.dart';

import 'package:puzzle/design_patterns/abstract_factory/BoardSpace/ITicTacToeBoardSpace.dart';


class FlutterTicTacToeGWBoardSpace implements ITicTacToeBoardSpace{

  TicTacToeGame _tictactoe;
  FlutterTicTacToeGWBoardSpace(TicTacToeGame tictactoe) { 
    this._tictactoe=tictactoe; 
  } 


  @override
  Widget render(int idx){
    // print('${(this._tictactoe.windex!=-1)?this._tictactoe.winstates[this._tictactoe.windex]:'chill'}');
    return Container(
      decoration: BoxDecoration(
        color: this._tictactoe.winner 
                ?Colors.lightGreen[200]
                :this._tictactoe.board[_tictactoe.vdx]==0
                ?Colors.yellow:Colors.white, 
        border: Border.all(
          color: Colors.black,
          width: 1,
        ),
        borderRadius: BorderRadius.circular(6)
      ),
      margin: const EdgeInsets.all(3),
      width: 50,
      height:50,
      child: Center(child: Text('${_tictactoe.board[idx]}',
        style: TextStyle(fontSize: 45),
        textAlign: TextAlign.center,
      ),)
    );

  }
}