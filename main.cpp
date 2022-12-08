#include <iostream>
#include <typeinfo>
#include <vector>
#include "./board/board.h"
#include "./pieces/piece.h"
#include "./game/game.h"
#include "./pieces/knight.h"
#include "./pieces/king.h"
// #include "./pieces/rook.h"
class RookPiece;
// class QueenPiece;
class Piece;

int main() {

  Game game;

  int endposking[2] = { 4, 5 };
  game.board.move_piece(game.board.grid[7][4], endposking);

  int endposrook[2] = {2, 6};
  game.board.move_piece(game.board.grid[0][0], endposrook);

  bool check = game.board.in_check(game.board.grid[4][5]);
  std::cout << check << std::endl;

  game.board.print_board();

}