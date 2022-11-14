#include "bishop.h"
#include <string>

BishopPiece::BishopPiece(int posX, int posY, std::string color) : Piece(posX, posY) {
  value = "rook";
  color = color;
}