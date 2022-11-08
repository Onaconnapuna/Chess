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

}