#include <iostream>
#include <ctime>

 enum button {
 moveUp = 'w',
 moveDown = 's',
 moveLeft = 'a',
 moveRight = 'd'
 };
class PuzzleGame{
  public: 
   char Choice;
  void Initialize(char[3][3]);
  void DrawBoard(char[3][3]);
  void Checkspace(int&, int&, char[3][3]);
  void Randomize(char[3][3]);
  void Move(char[3][3], const button);
  int checkwin(char[3][3]);
};