import { Component } from 'react';
import  {ttt} from  '../../../services/TicTacToeGame';
import { ES6TicTacToeBoardSpace } from  '../BoardSpace/ES6TicTacToeBoardSpace';
export class ES6TicTacToeBoard extends Component {

  state = {
    data:Array(9).fill(1).map((_, i) => ({
      component: ttt,
      id: i
    }))

  };

  constructor(){
    super();
    document.body.addEventListener('keyup', this.myEfficientFn);
    debounce = debounce.bind(this);
    this.ec=0;
  }

  myEfficientFn =
  debounce(event =>{
      this.ec++;
      if(this.ec<2){
        this.build();
        return;
      }
      this.ec=0;
      // All the taxing stuff you do
      console.log(event.key);
      const idx = ttt.find(ttt.board,0);
      switch(event.key) {
        case "ArrowUp":
          if(idx-3>-1)ttt.gamePlay(idx-3);
          break;
        case "ArrowDown":
          if(idx+3<9)ttt.gamePlay(idx+3);
          break;
        case "ArrowLeft":
          if(idx-1>-1)ttt.gamePlay(idx-1);
          break;
        case "ArrowRight":
          if(idx+1<9)ttt.gamePlay(idx+1);
          break;
          default:
            const text = "I have never heard of that...";
            console.log(text,event.key);
      } this.build();
    }, 400,true);
  

  build = () => {
    // console.log('updating..',ttt.find(ttt.board,0));
    // console.dir(ttt.board);
    this.forceUpdate();
  }

  handleKeyPress = (event) => {
    console.log(event.key)
  }

  keyPressHandler(){
    var cmdDown = false;
    console.log('key event handler added');
    document.body.addEventListener('keydown', (event) => {
      var key = event.keyCode || event.charCode || 0;
      if ([91,93,224,17].indexOf(key) !== -1) {
        cmdDown = true;
      }
      console.log('CMD DOWN: ' + cmdDown.toString(), event.key);    
    });

    document.body.addEventListener('keyup', (event) => {
      var key = event.keyCode || event.charCode || 0;
      if ([91,93,224,17].indexOf(key) !== -1) {
        cmdDown = false;
      }
      console.log('CMD DOWN: ' + cmdDown.toString(), event.key);
    });
  }
  
  render() {
    return (
      <div className="main-board">
      <h3>{ttt.getText()}</h3>
        <div className="grid-container">{this.state.data.map((dynamicComponent, i) => <ES6TicTacToeBoardSpace 
          build = {this.build} key = {i} componentData = {dynamicComponent}/>)}</div>
      </div>
      ) ;
  }
}

// Returns a function, that, as long as it continues to be invoked, will not
// be triggered. The function will be called after it stops being called for
// N milliseconds. If `immediate` is passed, trigger the function on the
// leading edge, instead of the trailing.
function debounce(func, wait, immediate) {
	var timeout;
	return function() {
		var context = this, args = arguments;
		var later = function() {
			timeout = null;
			if (!immediate) func.apply(context, args);
		};
		var callNow = immediate && !timeout;
		clearTimeout(timeout);
		timeout = setTimeout(later, wait);
		if (callNow) func.apply(context, args);
	};
}



//window.addEventListener('keyup', myEfficientFn);

