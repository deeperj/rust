
export default class TicTacToeGame 
{

  constructor(){
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
    this.board = [1, 4, 2, 6, 0, 5, 7, 3, 8];
    this.vdx = this.zdx = this.find(this.board, 0);
  }
  
  next(min, max){return min + Math.floor(Math.random() * max);}

  randomizeBoard() 
  {
    this.board = [-1, -1, -1, -1, -1, -1, -1, -1, -1];
    for (let i = 0; i < this.BSZ2; i++) {
      let fixed = false;
      while (!fixed) {
        let fix = this.next(0, this.BSZ2);
        if (this.board[fix] === -1) {
          this.board[fix] = i;
          fixed = true;
        }
      }
    }
  }


  reset() 
  {
    this.winner = false;
    this.randomizeBoard();
  }

  drawBoard() 
  {
    let sb = '';
    for (var i = 0; i < this.BSZ; i++) {
      for (var j = 0; j < this.BSZ; j++)
        if (this.board[i * this.BSZ + j] === 0){
          sb+="X";
        }else{
          sb+=(this.board[i * this.BSZ + j]);
        }
      sb+='\n';
    }console.log(sb);
  }

  getText() 
  {
    if (this.winner)
      return "we have a winner!";
    else if (!this.validChoice())
      return "invalid choice";
    else
      return "Number puzzle";
  }

  gameLoop() 
  {
    new TicTacToeGame().loop();
  }

  loop() 
  {
    while (!this.winner) {
      this.drawBoard();
      this._c =  this.getChoice();
      this.zdx = this.find(this.board, 0);
      this.vdx = this.find(this.board, this._c);
//      print(validMoves[zdx]);
      if (this._c === -1 || !this.validChoice()) {
        console.log("invalid choice");
        break;
      }
      this.swapPieces();
      this.winner = this.checkWinner();
      if (this.winner) {
        this.drawBoard();
        console.log("we have a winner!");
      }
    }
  }

  swapPieces() 
  {
    this.board[this.zdx] = this.board[this.vdx];
    this.board[this.vdx] = 0;
  }

  validChoice() 
  {
    return this.validMoves[this.zdx].includes(this.vdx);
  }

  getChoice() 
  {
    // const readline = require("readline");
    // const rl = readline.createInterface({
    //     input: process.stdin,
    //     output: process.stdout
    // });
    // let line = '';
    // rl.question("Where do you live ? ", country=>{
    //   console.log(`i am here ${country}`);
    //   line=country
    //   rl.close();
    // });
    let line = prompt('select a value: ');
    try {
      return parseInt(line.trim());
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
      this.reset();
      return;
    }
    this.zdx = this.find(this.board, 0);
    this.vdx = idx;
    if (!this.validChoice()) {
      console.log(`${this.zdx} invalid choice ${idx}`);
      return;
    }
    this.swapPieces();
    this.winner = this.checkWinner();
  }

  checkWinner()
  {
    if (!((this.board[0] === 0 || this.board[0] === 1) &&
        (this.board[this.BSZ2 - 1] === 0 || this.board[this.BSZ2 - 1] == 8))) {
      return false;
    }
    //check for winner step 2 check remaining board spaces
    for (let i = 0; i < this.BSZ2; i++) {
      if (i > 0 && i < this.BSZ2 - 1) {
        if ((this.board[i] !== 0 &&
            i > 1 &&
            (this.board[i - 1] === 0
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
export let ttt = new TicTacToeGame();
