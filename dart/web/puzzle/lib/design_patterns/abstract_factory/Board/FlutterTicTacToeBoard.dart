import 'package:flutter/material.dart';
import 'package:puzzle/design_patterns/abstract_factory/Board/ITicTacToeBoard.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardSpace/ITicTacToeBoardSpace.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardSpace/FlutterTicTacToeBoardSpace.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardLine/FlutterTicTacToeBoardLine.dart';
import 'package:puzzle/design_patterns/abstract_factory/BoardLine/ITicTacToeBoardLine.dart';
import 'package:puzzle/TicTacToeGame.dart';

class FlutterTicTacToeBoard implements ITicTacToeBoard {
  TicTacToeGame _tictactoe;
  FlutterTicTacToeBoardLine _lines;
  final ValueChanged<int> onChanged;

  FlutterTicTacToeBoard(TicTacToeGame tictactoe, @required this.onChanged) {
    this._tictactoe = tictactoe;
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
                            new FlutterTicTacToeBoardSpace(this._tictactoe).render(x * 3 + y)
                        ],
                      )
                  ]),
              this._lines.render(),
            ],
          ),
        ]);
  }
}
