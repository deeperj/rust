import logo from './logo.svg';
import './App.css';
import { ES6TicTacToeGWBoard } from './design_patterns/abstract_factory/Board/ES6TicTacToeGWBoard';

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <ES6TicTacToeGWBoard />
      </header>
    </div>
  );
}

export default App;
