#include "queen.h"
#include <string>

QueenPiece::QueenPiece(int posX, int posY, std::string color) : Piece(posX, posY) {
  value = "rook";
  color = color;
}