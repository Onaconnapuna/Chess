#include <iostream>
#include <typeinfo>
#include <vector>
#include "./board/board.h"
#include "./pieces/piece.h"
// #include "./pieces/rook.h"

int main() {

  Board board;

  board.create_board();

  board.print_board();

  // RookPiece rook(4, 4, "white");
  // board.grid[4][4] = rook;

  // std::vector<std::vector<int> > moves = rook.slideable_moves(board);

  // for (int i = 0; i < moves.size(); i++) {
  //   std::vector<int> delta = moves[i];
  //   std::cout << delta[0] << delta[1] << " ";
  // }
  std::cout << board.grid[0][0].color << std::endl;
  std::cout << board.grid[7][7].color << std::endl;
}