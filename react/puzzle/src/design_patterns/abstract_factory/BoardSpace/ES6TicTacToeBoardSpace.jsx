
import { Component } from 'react';
//import { TicTacToeGame } from  '../../../services/TicTacToeGame';

//import { ITicTacToeBoardSpace } from './ITicTacToeBoardSpace';


export class ES6TicTacToeBoardSpace extends Component{

  //TicTacToeGame _tictactoe;
  constructor() { 
    super();
  }

  bspace(id){
    let res= "boardspace "+(this.ttt.windex!=-1 
      && this.ttt.winstates[this.ttt.windex].includes(id))
      ?"usewhite":"usered";
    return "boardspace "+res;
  }
  handle(ttt,id){
    console.log('handling');
    //ttt.gamePlay(ttt.board[id]);
  }
  render(){
      this.ttt=this.props.componentData.component;
      const {component:ttt,id} = this.props.componentData;
      return (
        <div className={this.bspace(id)} onClick={this.handle(ttt,id)}>
          <div className="btext">{ttt.board[id]}</div>
        </div>
      );
  }
}