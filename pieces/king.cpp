#include "king.h"
#include <string>

KingPiece::KingPiece(int posX, int posY, std::string add_color, std::string add_symbol) : Piece(posX, posY) {
  value = "king";
  symbol = add_symbol;
  color = add_color;
  slideable = false;
  deltas = { { 1, 1 }, { 1 , -1 }, { -1, 1 }, { -1, -1 }, { 1, 0 }, { -1, 0 }, { 0, -1}, { 0, 1} };
}

// KingPiece in_check(Board& board) {

//   std::string color = color;
//   std::vector<std::vector<int>> valid_moves;

//   if (color == "white") {
//     for (int i = 0; i < board.black_pieces.size(); i++) {
//       valid_moves = board.black_pieces[i].valid_moves(board);
//       for (int i = 0; i < valid_moves.size(); i++) {
//         if (valid_moves[i][0] == position[0] && valid_moves[i][1] == position[1]) return true;
//       }
//       valid_moves.clear();
//     }
//   } else {
//     for (int i = 0; i < board.white_pieces.size(); i++) {
//       valid_moves = board.white_pieces[i].valid_moves(board);
//       for (int i = 0; i < valid_moves.size(); i++) {
//         if (valid_moves[i][0] == position[0] && valid_moves[i][1] == position[1]) return true;
//       }
//       valid_moves.clear();
//     }
//   }
//   return true;

// }