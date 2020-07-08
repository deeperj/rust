import 'package:puzzle/design_patterns/abstract_factory/Board/ITicTacToeBoard.dart';
import 'package:puzzle/TicTacToeGame.dart';


abstract class ITicTacToeUIFactory {
  ITicTacToeBoard getBoard(TicTacToeGame tictactoe,bool glow);
}