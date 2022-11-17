#include "pawn.h"
#include <string>

PawnPiece::PawnPiece(int posX, int posY, std::string add_color) : Piece(posX, posY) {
  value = "pawn";
  color = add_color;
}