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

  // Board board;

  Game game;

  // game.board.create_board();
  // game.board.print_board();

  // int end_pos[2] = { 4, 4 };
  int end_pos2[2] = { 4, 5 };
  // game.board.move_piece(game.board.grid[0][4], end_pos);
  game.board.move_piece(game.board.grid[7][7], end_pos2);

  // for (int i = 0; i < game.board.white_pieces.size(); i++) {
  //   std::cout << game.board.black_pieces[i].position[0] << game.board.black_pieces[i].position[1] << std::endl;
  // }
  // RookPiece rook(4, 5, "white", "R");
  // game.board.grid[4][5] = rook;
  // std::cout << game.board.grid[4][5].symbol;
  std::cout << game.board.grid[4][5].position[0];
  std::cout << game.board.grid[4][5].position[1];

//   game.board.grid[4][5].position[0] = 4;
//   game.board.grid[4][5].position[1] = 5;

// std::cout << game.board.grid[4][5].position[0];
  // std::cout << game.board.grid[4][5].symbol;

  // std::cout << game.board.grid[7][7].position[0];
  // std::cout << game.board.grid[7][7].position[1];
  // std::cout << game.board.grid[4][5].value;

  // for (int i = 0; i < game.board.white_pieces.size(); i++) {
  //   std::cout << game.board.white_pieces[i].position[0];
  // }
  
  // std::vector<std::vector<int>> moves = game.board.grid[4][5].valid_moves(game.board);
  // std::cout << moves.size();
  // for (int i = 0; i < moves.size(); i++) {
  //   std::cout << moves[i][0] << moves[i][1] << std::endl;
  // }
  // std::cout << game.board.in_check(game.board.grid[4][4]);
  // game.board.print_board();

  // std::cout << game.board.grid[0][4].in_check(game.board);
  // std::cout << game.board.grid[0][4].value;
  std::cout << std::endl;
  game.board.print_board();

//   for (int i = 0; i < game.board.black_pieces.size(); i++) {
//     int start_pos = game.board.black_pieces[i].position[0];
//     int end_pos = game.board.black_pieces[i].position[1];
//     std::cout << start_pos << end_pos << std::endl;
//   }
// game.board.print_board();

  

  // std::vector<std::vector<int> > moves = knight.valid_moves(game.board);
  // std::cout << moves.size();
  // // game.board.print_board();
  // for (int i = 0; i < moves.size(); i++) {
  //   std::vector<int> delta = moves[i];
  //   std::cout << delta[0] << delta[1] << " ";
  // }
}