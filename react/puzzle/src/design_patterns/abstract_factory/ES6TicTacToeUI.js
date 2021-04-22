import 'package:flutter/material.dart';
import 'package:puzzle/design_patterns/abstract_factory/ITicTacToeUIFactory.dart';
import 'package:puzzle/design_patterns/abstract_factory/Board/ITicTacToeBoard.dart';
import 'package:puzzle/design_patterns/abstract_factory/Board/ES6TicTacToeBoard.dart';
import 'package:puzzle/design_patterns/abstract_factory/Board/ES6TicTacToeGWBoard.dart';
import 'package:puzzle/TicTacToeGame.dart';

class ES6TicTacToeUI implements ITicTacToeUIFactory {
  @override
  ITicTacToeBoard getBoard(TicTacToeGame tictactoe,bool glow, @required onChanged){
    return (glow?ES6TicTacToeGWBoard(tictactoe,onChanged): ES6TicTacToeBoard(tictactoe,onChanged));
  }
}