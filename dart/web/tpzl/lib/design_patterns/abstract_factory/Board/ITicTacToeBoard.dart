import 'package:puzzle/design_patterns/abstract_factory/BoardLine/ITicTacToeBoardLine.dart';
import 'package:flutter/material.dart';


abstract class ITicTacToeBoard {
  ITicTacToeBoardLine buildLines();
  Widget render();
}