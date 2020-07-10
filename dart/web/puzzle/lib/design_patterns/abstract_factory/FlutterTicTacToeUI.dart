import 'package:flutter/material.dart';
import 'package:puzzle/design_patterns/abstract_factory/ITicTacToeUIFactory.dart';
import 'package:puzzle/design_patterns/abstract_factory/Board/ITicTacToeBoard.dart';
import 'package:puzzle/design_patterns/abstract_factory/Board/FlutterTicTacToeBoard.dart';
import 'package:puzzle/design_patterns/abstract_factory/Board/FlutterTicTacToeGWBoard.dart';
import 'package:puzzle/TicTacToeGame.dart';

class FlutterTicTacToeUI implements ITicTacToeUIFactory {
  @override
  ITicTacToeBoard getBoard(TicTacToeGame tictactoe,bool glow, @required onChanged){
    return (glow?FlutterTicTacToeGWBoard(tictactoe,onChanged): FlutterTicTacToeBoard(tictactoe,onChanged));
  }
}