#include <iostream>
#include <typeinfo>
#include <vector>
#include "./board/board.h"
// #include "./pieces/piece.h"

int main() {

  Board board;

  board.create_board();
  board.place_pieces();

  int start_pos[2] = { 0, 0 };
  int end_pos[2] = { 3, 4 };

  bool result = board.move_piece(board, start_pos, end_pos);

  board.print_board();

}