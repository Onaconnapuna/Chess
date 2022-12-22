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
  
  game.board.move_piece(game.board.grid[0][3], pos2);
  game.board.move_piece(game.board.grid[0][7], pos3);

  game.board.print_board();

  // game.board.grid[0][0].moves_out_ of_check(game.board);
  
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
  // bool gameover = game.board.checkmate(game.board.grid[4][5]);
  // game.board.move_piece(game.board.grid[0][0], endpos1);
  //  game.board.print_board();
  // std::cout << gameover << std::endl;
  // int endpos[2] = {5, 4};
  // game.board.move_piece(game.board.grid[7][4], endpos);
  // std::cout << game.board.grid[6][0].color;
  // std::vector<std::vector<int>> moves = game.board.grid[7][4].valid_moves(game.board);
  // std::cout << moves.size() << std::endl;
  // for (int i = 0; i < moves.size(); i++) {
  //   std::cout << moves[i][0] << moves[i][1] << std::endl;
  // }
  // PawnPiece pawn(6, 0, "white", "P");
  // game.board.grid[6][0] = pawn;
  // std::cout << pawn.forward_dir;

  // for (int i = 0; i < game.board.grid[7].size(); i++) {
  //   std::cout << game.board.grid[7][i].value << std::endl;
  // }

  // std::cout << game.board.grid[6][0].forward_dir << std::endl;

  // for (int i = 0; i < game.board.black_pieces.size(); i++) {
  //   std::cout << game.board.black_pieces[i].color<< std::endl; 
  // }
// std::cout << game.board.grid[7][0].color << std::endl;
  // game.board.print_board() ;
  // std::cout << game.board.grid[4][5].color << std::endl;
  // std::cout << game.board.in_check(game.board.grid[4][5]);
}


// deep dup does work
// need to test checkmate and check more
// find out why pawn piece colors are unknown
