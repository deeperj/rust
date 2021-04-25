
import { Component } from 'react';

export class ES6TicTacToeBoardSpace extends Component{

  bspace = () =>{
    //console.dir(this.ttt);
    let res=((this.id==this.ttt.vdx) && !this.ttt.validChoice())?"usered":"usepink";
    res = (this.ttt.winner?"usegreen":res);
    res = (this.ttt.board[this.id]==0?"usewhite":res);
    return "boardspace "+res;
  }

  handle =()=>{
    this.setState({id:1})
    this.ttt.gamePlay(this.id);
    this.props.build();
  }

  render(){
      this.ttt=this.props.componentData.component;
      this.id=this.props.componentData.id;
      const {component:ttt,id} = this.props.componentData;
      return (
        <div className={this.bspace()} onClick={this.handle}>
          <div className="btext">{ttt.board[id]}</div>
        </div>
      );
  }
}