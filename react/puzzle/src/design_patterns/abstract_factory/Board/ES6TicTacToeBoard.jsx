import { Component } from 'react';
import  {ttt} from  '../../../services/TicTacToeGame';
//import { ITicTacToeBoard } from  './ITicTacToeBoard';
//import { ITicTacToeBoardSpace } from  '../BoardSpace/ITicTacToeBoardSpace';
import { ES6TicTacToeBoardSpace } from  '../BoardSpace/ES6TicTacToeBoardSpace';
// import { ES6TicTacToeBoardLine } from  './ES6TicTacToeBoardLine';
// import { ITicTacToeBoardLine } from  './ITicTacToeBoardLine';

export class ES6TicTacToeBoard extends Component {

  state = {
    data:Array(9).fill(1).map((_, i) => ({
      component: ttt,
      id: i
    }))

  };

  constructor() {
    super();
    // this.setState({
    //   data:Array(9).fill(1).map((_, i) => ({
    //     component: 'hi1',
    //     id: i
    //   }))
    // });
    //console.log(this.state.data);
  }


  buildLines() 
  {
    //return new ES6TicTacToeBoardLine(this._tictactoe);
  }

  render() {
    return (
      <div className="main-board">
        <div className="grid-container">{this.state.data.map((dynamicComponent, i) => <ES6TicTacToeBoardSpace 
        key = {i} componentData = {dynamicComponent}/>)}</div>
      </div>
      ) ;
  }
}
