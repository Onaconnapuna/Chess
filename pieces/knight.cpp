#include "knight.h"
#include <string>

KnightPiece::KnightPiece(int posX, int posY, std::string color) : Piece(posX, posY) {
  value = "rook";
  color = color;
}