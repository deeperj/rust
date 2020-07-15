import 'dart:math';
import 'dart:io';
import 'dart:convert';

class TicTacToeGame {
  final _random = new Random();
  bool winner = false;
  final List validMoves = const [
    [0, 1, 3],
    [1, 0, 2, 4],
    [2, 1, 5],
    [3, 0, 4, 6],
    [4, 1, 3, 5, 7],
    [5, 2, 4, 8],
    [6, 3, 7],
    [7, 6, 8, 4],
    [8, 5, 7]
  ];
  // List board = [-1,-1,-1,-1,-1,-1,-1,-1,-1];
  static const int BSZ = 3;
  static const int BSZ2 = 9;
  int vdx, zdx, _c;
  List board = [1, 4, 2, 6, 0, 5, 7, 3, 8];

  TicTacToeGame() {
    vdx = zdx = find(board, 0);
  }
  void randomizeBoard() {
    board = [-1, -1, -1, -1, -1, -1, -1, -1, -1];
    for (int i = 0; i < BSZ2; i++) {
      bool fixed = false;
      while (!fixed) {
        int fix = _next(0, BSZ2);
        if (board[fix] == -1) {
          board[fix] = i;
          fixed = true;
        }
      }
    }
  }

  int _next(int min, int max) => min + _random.nextInt(max - min);
  void reset() {
    winner = false;
    randomizeBoard();
  }

  void drawBoard() {
    var sb = new StringBuffer();
    for (var i = 0; i < BSZ; i++) {
      for (var j = 0; j < BSZ; j++)
        if (board[i * BSZ + j] == 0)
          sb.write("X");
        else
          sb.write(board[i * BSZ + j]);
      print(sb);
      sb.clear();
    }
  }

  String getText() {
    if (winner)
      return "we have a winner!";
    else if (!validChoice())
      return "invalid choice";
    else
      return "";
  }

  static void gameLoop() {
    new TicTacToeGame().loop();
  }

  void loop() {
    while (!winner) {
      drawBoard();
      _c = getChoice();
      zdx = find(board, 0);
      vdx = find(board, _c);
//      print(validMoves[zdx]);
      if (_c == -1 || !validChoice()) {
        print("invalid choice");
        continue;
      }
      swapPieces();
      winner = checkWinner();
      if (winner) {
        drawBoard();
        print("we have a winner!");
      }
    }
  }

  void swapPieces() {
    board[zdx] = board[vdx];
    board[vdx] = 0;
  }

  bool validChoice() {
    return validMoves[zdx].contains(vdx);
  }

  int getChoice() {
    stdout.write("select a value: ");
    var line = stdin.readLineSync(encoding: Encoding.getByName('utf-8'));
    try {
      return int.parse(line.trim());
    } on Exception {
      print("invalid input");
      return -1;
    }
  }

  int find(List a, int search) {
    for (var i = 0; i < a.length; i++) {
      if (a[i] == search) return i;
    }
    return -1;
  }

  void gamePlay(int idx) {
    if (winner) {
      reset();
      return;
    }
    zdx = find(board, 0);
    vdx = idx;
//      print(validMoves[zdx]);
    if (!validChoice()) {
      print("invalid choice ${idx}");
      return;
    }
    swapPieces();
    winner = checkWinner();
  }

  bool checkWinner() {
    if (!((board[0] == 0 || board[0] == 1) &&
        (board[BSZ2 - 1] == 0 || board[BSZ2 - 1] == 8))) {
      return false;
    }
    //check for winner step 2 check remaining board spaces
    for (int i = 0; i < BSZ2; i++) {
      if (i > 0 && i < BSZ2 - 1) {
        if ((board[i] != 0 &&
            i > 1 &&
            (board[i - 1] == 0
                ? board[i] < board[i - 2]
                : board[i] < board[i - 1]))) {
          // cout << "here" << i << endl;
          return false;
        }
      }
    }
    return true;
  }
}

void main() {
//   1. gameLoop();
//   2. drawBoard(); done
//   3. getChoice();
//   4. validChoice();
//   5. checkWinner();
//   6. randomizeBoard(); done
//   7. swapPiece();
  TicTacToeGame.gameLoop();
}
