#include <iostream>
#include <typeinfo>
#include <vector>
#include "./board/board.h"
using namespace std;

int main() {

  Board board;

  board.create_board();
  board.place_pieces(board);

  for (int i = 0; i < board.grid.size(); i++) {
    for (int j = 0; j < board.grid[i].size(); j++) {
      // if (board.grid[i][j].value && board.grid[i][j].value == "nil-square") {
      // }
      // cout << typeid(board.grid[i][j]).name() << " ";
      cout << board.grid[i][j].value << " ";
    }
    cout << endl;
  }

}