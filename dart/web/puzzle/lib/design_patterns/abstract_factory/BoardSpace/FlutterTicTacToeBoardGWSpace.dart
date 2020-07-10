import 'package:flutter/material.dart';
import 'package:puzzle/TicTacToeGame.dart';

import 'package:puzzle/design_patterns/abstract_factory/BoardSpace/ITicTacToeBoardSpace.dart';

class FlutterTicTacToeGWBoardSpace implements ITicTacToeBoardSpace {
  TicTacToeGame _tictactoe;
  final ValueChanged<int> onChanged;
  int _idx;
  FlutterTicTacToeGWBoardSpace(TicTacToeGame tictactoe, @required this.onChanged) {
    this._tictactoe = tictactoe;
  }

  void _handleTap() {
    onChanged(_idx);
  }

  @override
  Widget render(int idx) {
    _idx = idx;
    //print('${_idx}');
    return GestureDetector(
        onTap: _handleTap,
        child: Container(
            decoration: BoxDecoration(
                color: this._tictactoe.winner
                    ? Colors.lightGreen[200]
                    : (this._tictactoe.board[idx] == 0
                        ? Colors.white
                        : Colors.yellow),
                border: Border.all(
                  color: this._tictactoe.board[idx] == 0?
                          Colors.white:Colors.black,
                  width: 1,
                ),
                borderRadius: BorderRadius.circular(6)),
            margin: const EdgeInsets.all(3),
            width: 50,
            height: 50,
            child: Center(
              child: Text(
                this._tictactoe.board[idx] == 0?
                  "":'${_tictactoe.board[idx]}',
                style: TextStyle(fontSize: 45),
                textAlign: TextAlign.center,
              ),
            )));
  }
}
