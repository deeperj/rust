
import 'package:flutter/material.dart';
import 'package:puzzle/TicTacToeGame.dart';

import 'package:puzzle/design_patterns/abstract_factory/BoardSpace/ITicTacToeBoardSpace.dart';


class ES6TicTacToeBoardSpace implements ITicTacToeBoardSpace{

  TicTacToeGame _tictactoe;
  ES6TicTacToeBoardSpace(TicTacToeGame tictactoe) { 
    this._tictactoe=tictactoe; 
  } 


  @override
  Widget render(int idx){
    return Container(
      decoration: BoxDecoration(
        color: Colors.white, 
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