#include <iostream>
#include <typeinfo>
#include <vector>
#include "./board/board.h"
#include "./pieces/piece.h"
#include "./game/game.h"
#include "./pieces/knight.h"
// #include "./pieces/rook.h"
class RookPiece;
class QueenPiece;

int main() {

  // Board board;

  Game game;

  game.board.create_board();
  // game.board.print_board();

  
  KnightPiece knight(4, 4, "white", "N");
  game.board.grid[4][4] = knight;



  std::vector<std::vector<int> > moves = knight.stepable_moves(game.board);
  std::cout << moves.size();
  // game.board.print_board();
  for (int i = 0; i < moves.size(); i++) {
    std::vector<int> delta = moves[i];
    std::cout << delta[0] << delta[1] << " ";
  }
}