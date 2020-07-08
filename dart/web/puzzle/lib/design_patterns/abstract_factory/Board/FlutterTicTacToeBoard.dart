
import 'package:flutter/material.dart';
import 'package:puzzle/design_patterns/abstract_factory/Board/ITicTacToeBoard.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardSpace/ITicTacToeBoardSpace.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardSpace/FlutterTicTacToeBoardSpace.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardLine/FlutterTicTacToeBoardLine.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardLine/ITicTacToeBoardLine.dart';
import 'package:puzzle/TicTacToeGame.dart';
import 'dart:math';


class FlutterTicTacToeBoard implements ITicTacToeBoard{
  TicTacToeGame _tictactoe;
  FlutterTicTacToeBoardSpace _space;
  FlutterTicTacToeBoardLine _lines;

  FlutterTicTacToeBoard(TicTacToeGame tictactoe) { 
    this._tictactoe=tictactoe;
    this._space=this.getBoardSpace(); 
    this._lines=this.buildLines();
  }

  @override
  ITicTacToeBoardSpace getBoardSpace(){
    return new FlutterTicTacToeBoardSpace(this._tictactoe);
  }

  @override
  ITicTacToeBoardLine buildLines(){
    return new FlutterTicTacToeBoardLine(this._tictactoe);
  }

  @override
  Widget render(){
    return Column(
      crossAxisAlignment: CrossAxisAlignment.center,
      mainAxisAlignment: MainAxisAlignment.center,
      children: <Widget>[
        Container(
          child: Center(child: Text('${this._tictactoe.winner}',
            style: TextStyle(fontSize: 45),
            textAlign: TextAlign.center,
          ),)
        ),
        Stack(
          children:<Widget>[
            Column(
              crossAxisAlignment: CrossAxisAlignment.center,
              mainAxisAlignment: MainAxisAlignment.center,
              children:<Widget>[
              for (var x in [0,1,2])
                Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: <Widget>[
                    for(var y in [0,1,2])
                      this._space.render(x*3+y)
                  ],
                )
              ]
            ),
            this._lines.render(),            
          ],
        ),
      ]
    );
    
  }
}