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
  // board.print_board();

  RookPiece rook(4, 4, "white");
  board.grid[4][4] = rook;

  board.print_board();

  std::vector<std::vector<int> > moves = rook.slideable_moves(board);

  for (int i = 0; i < moves.size(); i++) {
    std::vector<int> delta = moves[i];
    std::cout << delta[0] << delta[1] << " ";
  }

}