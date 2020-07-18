#pragma once
#include "PuzzleGame.hpp"
class PuzzlePiece;
class PuzzleGame;
class PuzzleBoard {
private:
public:
	PuzzlePiece pieces[PuzzleGame::BSZ2];
	PuzzleBoard();
};