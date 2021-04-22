
export default class TicTacToeGame 
{}
  /*
  this.winner = false;
  this.validMoves =  [
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
  this.BSZ = 3;
  this.BSZ2 = 9;
  this.vdx;
  this.zdx;
  this._c;
  this.board = [1, 4, 2, 6, 0, 5, 7, 3, 8];

  constructor() 
  {
    this.vdx = this.zdx = this.find(board, 0);
  }
  
  randomizeBoard() 
  {
    this.board = [-1, -1, -1, -1, -1, -1, -1, -1, -1];
    for (let i = 0; i < this.BSZ2; i++) {
      let fixed = false;
      while (!fixed) {
        let fix = _next(0, BSZ2);
        if (this.board[fix] == -1) {
          this.board[fix] = i;
          fixed = true;
        }
      }
    }
  }

  _next(min, max) => min + Math.floor(Math.random() * max);

  reset() 
  {
    this.winner = false;
    randomizeBoard();
  }

  drawBoard() 
  {
    var sb;
    for (var i = 0; i < this.BSZ; i++) {
      for (var j = 0; j < this.BSZ; j++)
        if (this.board[i * this.BSZ + j] == 0)
          sb.append("X");
        else
          sb.append(board[i * this.BSZ + j]);
      print(sb);
      sb.clear();
    }
  }

  getText() 
  {
    if (this.winner)
      return "we have a winner!";
    else if (!validChoice())
      return "invalid choice";
    else
      return "";
  }

  gameLoop() 
  {
    new TicTacToeGame().loop();
  }

  loop() 
  {
    while (!this.winner) {
      drawBoard();
      this._c = getChoice();
      this.zdx = find(board, 0);
      this.vdx = find(board, _c);
//      print(validMoves[zdx]);
      if (this._c == -1 || !validChoice()) {
        print("invalid choice");
        continue;
      }
      swapPieces();
      this.winner = checkWinner();
      if (this.winner) {
        drawBoard();
        print("we have a winner!");
      }
    }
  }

  void swapPieces() 
  {
    this.board[this.zdx] = board[this.vdx];
    board[this.vdx] = 0;
  }

  validChoice() 
  {
    return validMoves[zdx].contains(vdx);
  }

  getChoice() 
  {
    console.log("select a value: ");
    let line = input('select a value: ');
    try {
      return int.parse(line.trim());
    } catch {
      return -1;
    }
  }

  find(a, search) {
    for (let i = 0; i < a.length; i++) {
      if (a[i] == search) return i;
    }
    return -1;
  }

  gamePlay(idx) 
  {
    if (this.winner) {
      reset();
      return;
    }
    this.zdx = find(this.board, 0);
    this.vdx = this.idx;
//      print(validMoves[zdx]);
    if (!validChoice()) {
      print("invalid choice ${idx}");
      return;
    }
    swapPieces();
    this.winner = checkWinner();
  }

  checkWinner()
  {
    if (!((this.board[0] == 0 || this.board[0] == 1) &&
        (board[this.BSZ2 - 1] == 0 || this.board[BSZ2 - 1] == 8))) {
      return false;
    }
    //check for winner step 2 check remaining board spaces
    for (let i = 0; i < this.BSZ2; i++) {
      if (i > 0 && i < this.BSZ2 - 1) {
        if ((this.board[i] != 0 &&
            i > 1 &&
            (this.board[i - 1] == 0
                ? this.board[i] < this.board[i - 2]
                : this.board[i] < this.board[i - 1]))) {
          // cout << "here" << i << endl;
          return false;
        }
      }
    }
    return true;
  }
}
*/