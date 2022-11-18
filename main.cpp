#include <iostream>
#include <typeinfo>
#include <vector>
#include "./board/board.h"
#include "./pieces/piece.h"
// #include "./pieces/rook.h"
class RookPiece;
class QueenPiece;

int main() {

  Board board;

  board.create_board();
  // board.print_board();
  // int start_pos[] = {0, 0};
  // int end_pos[] = {3, 3};
  // board.move_piece(board, start_pos, end_pos);
  board.print_board();
  
  QueenPiece rook(3,3, "white");
  board.grid[3][3] = rook;

  std::vector<std::vector<int> > moves = rook.slideable_moves(board);
  // std::cout << moves.size();
  // board.print_board();
  for (int i = 0; i < moves.size(); i++) {
    std::vector<int> delta = moves[i];
    std::cout << delta[0] << delta[1] << " ";
  }
  // std::cout << board.grid[0][0].color << std::endl;
  // std::cout << board.grid[7][7].color << std::endl;

  // std::cout << board.grid[7][0].value << std::endl;
  // std::cout << board.grid[7][0].color << std::endl;
}