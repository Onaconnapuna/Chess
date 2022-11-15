#include "rook.h"
#include <string>

RookPiece::RookPiece(int posX, int posY, std::string color) : Piece(posX, posY) {
  value = "rook";
  slideable = true;
  color = color;
  deltas = { {-1, 0}, {0, 1}, {1, 0}, {-1, 0} };
}