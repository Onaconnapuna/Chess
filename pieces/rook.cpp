#include "rook.h"
#include <string>

RookPiece::RookPiece(int posX, int posY, std::string color) : Piece(posX, posY) {
  value = "rook";
  color = color;
}