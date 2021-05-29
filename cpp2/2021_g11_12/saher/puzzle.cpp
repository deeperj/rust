#include "PuzzleGame.h"
#include "grid.h"

PuzzleGame::PuzzleGame()
{
  initscr();                      
  curs_set(false);                
  noecho();
  getmaxyx(stdscr, wRow, wCol);
  dim = 3;
  instructionIndex = 0;
  state = PRE_GAME;
  menu[PRE_GAME] = &PuzzleGame::preMenu;
  menu[IN_GAME] = &PuzzleGame::ingame;
  menu[POST_GAME] = &PuzzleGame::winscreen;
  canMove[0] = &PuzzleGame::canMoveUp;
  canMove[1] = &PuzzleGame::canMoveDown;
  canMove[2] = &PuzzleGame::canMoveLeft;
  canMove[3] = &PuzzleGame::canMoveRight;
  moveGrid[0] = &PuzzleGame::moveUp;
  moveGrid[1] = &PuzzleGame::moveDown;
  moveGrid[2] = &PuzzleGame::moveLeft;
  moveGrid[3] = &PuzzleGame::moveRight;
}

PuzzleGame::~PuzzleGame()
{
  clearGrid();
  instructions.clear();
  dim = instructionIndex = 0;
}
void PuzzleGame::run()
{
  while(state != QUIT_GAME)
    {
     (this->*menu[state])();
      refresh();
      clear();
    }
}
void PuzzleGame::preMenu()
{
mvprintw(wRow/9, wCol/2 - 7, "%s", "Welcome to Puzzle Game");

mvprintw(wRow/5, wCol/2 - 7, "%s", "Dimension: ");
  mvprintw(wRow/5, wCol/2 + 4, "%i", dim);
  mvprintw(wRow/5, wCol/2 + 5, "%s", "x");
  mvprintw(wRow/5, wCol/2 + 6, "%i", dim);

  mvprintw(wRow/2, wCol/2 - 23, "%s", "Press left/right arrow keys to modify dimension");
     
  mvprintw(wRow/2+2, wCol/2 - 10, "%s", "Press enter to begin");

int input = getch();
  switch(input)
  {
    case 67:    if(dim == 3)
      dim++;
      break;
    case 68:    if(dim == 4)
                        dim--;
      break;
     case 10:    currState.setDim(dim);
        generateRand();
        instructions.push_back(currState);
        state = IN_GAME;
      break;

        default:    
        break;
    }
}

void PuzzleGame::ingame()
{
    
  mvprintw(wRow/9, wCol/2 - 7, "%s", "PuzzleGame");

    
  print(currState);

   
  mvprintw(wRow/2 + 4, wCol/2 - 12, "%s", "Press arrow keys to move");

 int input = getch();

    
  switch(input)
    {
     case 65:    
      if(canMoveDown(currState))
        {
          moveDown(currState);
          instructions.push_back(currState);
        }
     break;

        // Down arrow
        case 66:    
         if(canMoveUp(currState))
            {
              moveUp(currState);
              instructions.push_back(currState);
              }
          break;

        case 67:    
         if(canMoveLeft(currState))
            {
             moveLeft(currState);
             instructions.push_back(currState);
              }
         break;

        case 68:    
         if(canMoveRight(currState))
          {
            moveRight(currState);
            instructions.push_back(currState);
           }
         break;

    }

   
    if(isGoal(currState))
    {
        state = POST_GAME;
        instructionIndex = instructions.size()-1;
        refresh();
        erase();
    }
}

void PuzzleGame::winscreen()
{
    {
    print(instructions[instructionIndex]);

    mvprintw(wRow/9, wCol/2 - 7, "%s", "PuzzleGame");
      
    mvprintw(wRow/2+2, wCol/2 - 5, "You Won", instructionIndex+1);

    mvprintw(wRow/2+4, wCol/2 - 24, "%s", "Press left/right arrow keys to see your previous moves");
    
  
  int input = getch();

    switch(input)
    {
    
    case 67:    if(instructionIndex < instructions.size()-1)
    instructionIndex++;
    break;

    
    case 68:    if(instructionIndex > 0)
    instructionIndex--;
    break;

case 10:    clearGrid();
  currState.setDim(dim);
  generateRand();
  instructions.push_back(currState);
  state = IN_GAME;
  clear();
  break;
        }

    }
}

int PuzzleGame::posOf(int num, const grid &g)
{
  for(int i = 0; i < g.dim * g.dim; i++)
  if(g.arr[i] == num)
  return i;
  return -1;
}

bool PuzzleGame::isGoal(const grid &g)
{
  for(int i = 0; i < dim*dim - 1; i++)
  if(g.arr[i] != i+1)
  return false;
  return !g.arr[dim*dim - 1];
}
bool PuzzleGame::canMoveUp(const grid &g)
{
  return posOf(0, g) >= dim;
}
bool PuzzleGame::canMoveDown(const grid &g)
{
  return posOf(0, g) < (dim*dim - dim);
}
bool PuzzleGame::canMoveLeft(const grid &g)
{
  return posOf(0, g) % dim;
}
bool PuzzleGame::canMoveRight(const grid &g)
{
  return (posOf(0, g) % dim) != (dim - 1);
}
void PuzzleGame::moveUp(grid &g)
{
  swap(posOf(0, g) - g.dim, posOf(0, g), g);
}
void PuzzleGame::moveDown(grid &g)
{
  swap(posOf(0, g) + g.dim, posOf(0, g), g);
}
void PuzzleGame::moveLeft(grid &g)
{
  swap(posOf(0, g) - 1, posOf(0, g), g);
}
void PuzzleGame::moveRight(grid &g)
{
  swap(posOf(0, g) + 1, posOf(0, g), g);
}
void PuzzleGame::swap(int i, int j, grid &g)
{
  int temp = g[i];
  g[i] = g[j];
  g[j] = temp;
}
void PuzzleGame::generateRand()
{
  srand(time(NULL));
  for(int i = 0; i < dim*dim; i++)
  currState[i] = i;

    for(int i = 0; i < dim*dim; i++)
    {
    int j = rand() % dim*dim;
    swap(i, j, currState);
    }
int inversions = inversionCount();
  if((dim%2 && inversions%2) ||
  (!dim%2 && (!inversions%2 && !(posOf(0, currState)/4)%2) || (inversions%2 && (posOf(0, currState)/4)%2)))
  decrementInversionCount();
}
int PuzzleGame::inversionCount()
{
    int count = 0;
    for(int i = 0; i < dim*dim - 1; i++)
    for(int j = i+1; j < dim*dim; j++)
    if(currState[j] && currState[i] && currState[i] > currState[j])
    count++;
    return count;
}
void PuzzleGame::decrementInversionCount()
{
  for(int i = 0; i < dim*dim - 1; i++)
  for(int j = i+1; j < dim*dim; j++)
  if(currState[j] && currState[i] && currState[i] > currState[j])
  {
   swap(i, j, currState);
      return;
  }
}
void PuzzleGame::print(const grid &g){
  for(int i = 0, j = dim-3; i < dim*dim; i++)
    {
        if(i%dim == 0 && i > dim-1)
            j += 2;
        if(g.arr[i])
            mvprintw(wRow/3 - dim + j, wCol/2 - (dim+dim-1) + (i%dim)*4,"%i", g.arr[i]);
        else
            mvprintw(wRow/3 - dim + j, wCol/2 - (dim+dim-1) + (i%dim)*4, "%s", " ");
    }
}
void PuzzleGame::clearGrid(){
    for(int i = 0; i < 4; i++)
        clearGrid(currState.child[i]);
    instructions.clear();
    instructionIndex = 0;
}
void PuzzleGame::clearGrid(grid* &root)
{
  if(root)
    {
    for(int i = 0; i < 4; i++)
    {
            clearGrid(root->child[i]);
            if(root->child[i])
                delete root->child[i];
            root->child[i] = nullptr;
    }
    delete root;
    root = nullptr;
    }
}
