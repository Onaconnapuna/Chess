#include <iostream>
#include <typeinfo>
#include <vector>
#include "./board/board.h"
#include "./pieces/piece.h"
#include "./pieces/rook.h"

int main() {

  Board board;

  board.create_board();
  board.place_pieces();

  // int start_pos[2] = { 0, 0 };
  // int end_pos[2] = { 3, 4 };

  // bool result = board.move_piece(board, start_pos, end_pos);

  RookPiece rook(4, 4, "white");

  // board.print_board();

  // std::vector<std::vector<int> > moves = rook.slideable_moves(board);

  // for (int i = 0; i < moves.size(); i++) {
  //   std::vector<int> move = moves[i];
  //   std::cout << move[0] << move[1] << std::endl;
  // }

  std::cout << rook.value << rook.color << rook.slideable << std::endl;

}