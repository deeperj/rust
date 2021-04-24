import logo from './logo.svg';
import './App.css';
import { ES6TicTacToeBoard } from './design_patterns/abstract_factory/Board/ES6TicTacToeBoard';

function App() {
  return (
    <div className="App">
      <header className="App-header">
        {/* <img src={logo} className="App-logo" alt="logo" /> */}
        <ES6TicTacToeBoard/>
      </header>
    </div>
  );
}

export default App;
