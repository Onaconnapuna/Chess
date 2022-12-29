#include <iostream>
#include <typeinfo>
#include <vector>
#include "./board/board.h"
#include "./pieces/piece.h"
#include "./game/game.h"
#include "./pieces/knight.h"
#include "./pieces/king.h"
// #include "./pieces/rook.h"
// class RookPiece;
// class KingPiece;
// class QueenPiece;
class Piece;

int main() {

  Game game;

  int endposking[2] = { 4 , 5 };
  game.board.move_piece(game.board.grid[7][4], endposking);

  int endposrook[2] = {2, 5};
  game.board.move_piece(game.board.grid[0][0], endposrook);

  // bool check = game.board.in_check(game.board.grid[4][5]);
  // std::cout << check << std::endl;

  int pos2[2] = { 2, 6 };
  int pos3[2] = { 2, 4};
  int pos4[2] = { 5, 0 };
  
  game.board.move_piece(game.board.grid[0][3], pos2);
  game.board.move_piece(game.board.grid[0][7], pos3);
  game.board.move_piece(game.board.grid[7][0], pos4);

  game.board.print_board();
  bool gameover = game.board.checkmate(game.board.grid[4][5]);

  std::cout << gameover << std::endl;

  // bool in_check = game.board.in_check(game.board.grid[4][6]);
  // std::cout << in_check << std::endl;

  // game.board.print_board();
  
} 


// deep dup does work
// need to test checkmate and check more
// find out why pawn piece colors are unknown
