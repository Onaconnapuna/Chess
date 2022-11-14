#include "pawn.h"
#include <string>

PawnPiece::PawnPiece(int posX, int posY, std::string color) : Piece(posX, posY) {
  value = "rook";
  color = color;
}