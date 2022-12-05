#include <iostream>
#include <typeinfo>
#include <vector>
#include "./board/board.h"
#include "./pieces/piece.h"
#include "./game/game.h"
#include "./pieces/knight.h"
// #include "./pieces/rook.h"
// class RookPiece;
// class QueenPiece;
class Piece;

int main() {

  // Board board;

  Game game;

  // game.board.create_board();
  // game.board.print_board();

  int end_pos[2] = { 0, 1 };
  game.board.move_piece(game.board.grid[0][0], end_pos);

  // game.board.print_board();

  for (int i = 0; i < game.board.black_pieces.size(); i++) {
    int start_pos = game.board.black_pieces[i].position[0];
    int end_pos = game.board.black_pieces[i].position[1];
    std::cout << start_pos << end_pos << std::endl;
  }
game.board.print_board();


  // std::vector<std::vector<int> > moves = knight.valid_moves(game.board);
  // std::cout << moves.size();
  // // game.board.print_board();
  // for (int i = 0; i < moves.size(); i++) {
  //   std::vector<int> delta = moves[i];
  //   std::cout << delta[0] << delta[1] << " ";
  // }
}