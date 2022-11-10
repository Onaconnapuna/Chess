#include <iostream>
#include <typeinfo>
#include <vector>
#include "./board/board.h"
using namespace std;

int main() {

  Board board;

  board.create_board();
  board.place_pieces(board);
  board.print_board(board);

  int start_pos[2] = { 0 , 0 };
  int end_pos[2] = { 3, 4 };

  bool result = board.move_piece(board, start_pos, end_pos);
  // cout << result << endl;

  board.print_board(board);

}