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
class KingPiece;
// class QueenPiece;
class Piece;

int main() {

  Game game;

  int endposking[2] = { 4, 5 };
  game.board.move_piece(game.board.grid[7][4], endposking);

  int endposrook[2] = {2, 5};
  game.board.move_piece(game.board.grid[0][0], endposrook);

  bool check = game.board.in_check(game.board.grid[4][5]);
  std::cout << check << std::endl;

  int pos2[2] = { 2, 6 };
  int pos3[2] = { 2, 4};
  
  game.board.move_piece(game.board.grid[0][3], pos2);
  // game.board.move_piece(game.board.grid[0][7], pos3);

  game.board.print_board();
  
  // int endpos1[2] = { 5, 4 };
  // game.board.move_piece(game.board.grid[6][5], endpos1);
  // int endpos2[2] = {3, 4};
  // game.board.move_piece(game.board.grid[1][5], endpos2);
  // int endpos3[2] = { 4, 6 };
  // game.board.move_piece(game.board.grid[6][6], endpos3);
  // int endpos4[2] = {4, 7};
  // game.board.move_piece(game.board.grid[0][3], endpos4);
  // int endpos6[2] = { 5, 5 };
  // // game.board.print_board();
  // game.board.move_piece(game.board.grid[6][4], endpos6);
  bool gameover = game.board.checkmate(game.board.grid[4][5]);
  // game.board.move_piece(game.board.grid[0][0], endpos1);
  //  game.board.print_board();
  std::cout << gameover << std::endl;
  // int endpos[2] = {5, 4};
  // game.board.move_piece(game.board.grid[7][4], endpos);

  // std::vector<std::vector<int>> moves = game.board.grid[5][4].valid_moves(game.board);

  // for (int i = 0; i < moves.size(); i++) {
  //   std::cout << moves[i][0] << moves[i][1] << std::endl;
  // }

  // game.board.print_board();


}