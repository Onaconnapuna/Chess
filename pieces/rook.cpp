#include "rook.h"
#include <string>

RookPiece::RookPiece(int posX, int posY, std::string add_color) : Piece(posX, posY) {
  value = "rook";
  slideable = true;
  color = add_color;
  deltas = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
}