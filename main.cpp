#include <iostream>
#include <typeinfo>
#include <vector>
#include <map>
#include "./board/board.h"
#include "./pieces/piece.h"
#include "./game/game.h"
#include "./pieces/knight.h"
#include "./pieces/king.h"
#include "./pieces/pawn.h"
// #include "./pieces/rook.h"
// class RookPiece;
// class KingPiece;
// class QueenPiece;
class Piece;

int main() {

  Game game;

  game.start_match(game.board);

  // std::map<std::string, std::vector<std::string>> moves = game.player_white.all_valid_moves(game.board);
  // std::map<std::string, std::vector<std::string>>::iterator it;
  // for (it = moves.begin(); it != moves.end(); it++) {
  //   std::cout << it->first << std::endl;
  //   for (int i = 0; i < it->second.size(); i++) {
  //     std::cout << it->second[i]<< std::endl;
  //   }
  // }

  std::cout << game.player_white.display_moves(game.board) << std::endl;
  game.board.print_board();

  // std::vector<std::vector<int>> moves = game.board.grid[7][1].valid_moves(game.board);
  //  for (int j = 0; j < moves.size(); j++) {
  //       std::cout << moves[j][0] << moves[j][1] << std::endl;
  //     }
  // int endposking[2] = { 5, 5 };
  // game.board.move_piece(game.board.grid[7][4], endposking);

  // int endposrook[2] = {2, 5};
  // game.board.move_piece(game.board.grid[0][0], endposrook);

  // bool check = game.board.in_check(game.board.grid[5][5]);
  // std::cout << check << std::endl;

  // int pos2[2] = { 2, 6 };
  // int pos3[2] = { 2, 4};
  // int pos4[2] = { 4 , 0 };
  
  // game.board.move_piece(game.board.grid[0][3], pos2);
  // game.board.move_piece(game.board.grid[0][7], pos3);
  // game.board.move_piece(game.board.grid[7][0], pos4);

  // for (int i = 0; i < game.board.white_pawns.size(); i++) {
  //   game.board.white_pawns[i].valid_moves(game.board);
  // }

  // game.board.print_board();
  // bool gameover = game.board.checkmate(game.board.grid[5][5]);

  // std::cout << gameover << std::endl;

  // bool in_check = game.board.in_check(game.board.grid[4][6]);
  // std::cout << in_check << std::endl;

  // game.board.print_board();
  // std::cout << typeid(game.board.grid[0][0].PawnPiece).name() << std::endl;
  // game.board.grid[5][5].hello();

  // std::vector<std::vector<int>> moves = game.board.grid[5][5].valid_moves(game.board);
  
  // for (int i = 0; i < moves.size(); i++) {
  //   std::cout << moves[i][0] << moves[i][1] << std::endl;
  // }

  // for (int i = 0; i < game.board.grid.size(); i++) {
  //   for (int j = 0; j < game.board.grid.size(); j++) {
  //     std::string name = typeid().name();
  //     std::cout << name << std::endl;
  //   }
  // }
} 


// deep dup does work
// need to test checkmate and check more
// find out why pawn piece colors are unknown




// We can display moves to the console;
// cin a string with the display moves func 
//return it if its included as a key in the map, return empty if its not selected 
// in another func calles select move, call display moves, if display moves returns an empty string, call again
// in select_move if user types cancel, call display moves again
// in another func, called make move, call select move, if select move fails to return a move
 