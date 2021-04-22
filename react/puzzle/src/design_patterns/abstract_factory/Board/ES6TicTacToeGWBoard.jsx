
import { Component } from 'react';
import { TicTacToeGame } from  '../../../services/TicTacToeGame';
import { ITicTacToeBoard } from  './ITicTacToeBoard';

class ES6TicTacToeGWBoard extends  Component
{
  // this._tictactoe;
  // this.onChanged;
  // this._lines; // ES6TicTacToeBoardLine

  construtor(tictactoe, onChanged)
  {
    this._tictactoe = tictactoe;
    //this._space = this.getBoardSpace(onChanged);
    this._lines = this.buildLines();
  }


  buildLines() 
  {
    return new ES6TicTacToeBoardLine(this._tictactoe);
  }

  render()
  {
    return <h1>Hello World!</h1>
  }
}

export default ES6TicTacToeGWBoard;