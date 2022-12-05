#include "king.h"
#include <string>

KingPiece::KingPiece(int posX, int posY, std::string add_color, std::string add_symbol) : Piece(posX, posY) {
  value = "king";
  symbol = add_symbol;
  color = add_color;
  slideable = false;
  deltas = { { 1, 1 }, { 1 , -1 }, { -1, 1 }, { -1, -1 }, { 1, 0 }, { -1, 0 }, { 0, -1}, { 0, 1} };
}

KingPiece in_check(Board& board) {

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
        
    }
  }

}