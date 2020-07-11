import 'package:flutter/material.dart';
import 'package:puzzle/design_patterns/abstract_factory/Board/ITicTacToeBoard.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardSpace/ITicTacToeBoardSpace.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardSpace/FlutterTicTacToeBoardGWSpace.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardLine/FlutterTicTacToeBoardLine.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardLine/ITicTacToeBoardLine.dart';
import 'package:puzzle/TicTacToeGame.dart';

import '../../../TicTacToeGame.dart';

class FlutterTicTacToeGWBoard implements ITicTacToeBoard {
  TicTacToeGame _tictactoe;
  final ValueChanged<int> onChanged;
  FlutterTicTacToeBoardLine _lines;

  FlutterTicTacToeGWBoard(TicTacToeGame tictactoe,@required this.onChanged) {
    this._tictactoe = tictactoe;
    //this._space = this.getBoardSpace(onChanged);
    this._lines = this.buildLines();
  }


  @override
  ITicTacToeBoardLine buildLines() {
    return new FlutterTicTacToeBoardLine(this._tictactoe);
  }

  @override
  Widget render() {
    return Column(
        crossAxisAlignment: CrossAxisAlignment.center,
        mainAxisAlignment: MainAxisAlignment.center,
        children: <Widget>[
          Container(
              child: Center(
            child: Text(
              '${this._tictactoe.getText()}',
              style: TextStyle(fontSize: 45),
              textAlign: TextAlign.center,
            ),
          )),
          Stack(
            children: <Widget>[
              Column(
                  crossAxisAlignment: CrossAxisAlignment.center,
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: <Widget>[
                    for (var x
                        in new List<int>.generate(TicTacToeGame.BSZ, (i) => i))
                      Row(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: <Widget>[
                          for (var y in new List<int>.generate(
                              TicTacToeGame.BSZ, (i) => i))
                            //new List<int>.generate(3, (int index) => index * index); // [0, 1, 4]
                            (new FlutterTicTacToeGWBoardSpace(this._tictactoe,onChanged)).render(x * 3 + y)
                        ],
                      )
                  ]),
              //this._lines.render(),
            ],
          ),
        ]);
  }
}
