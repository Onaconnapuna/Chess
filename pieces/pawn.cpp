#include "pawn.h"
#include <string>

PawnPiece::PawnPiece(int posX, int posY, std::string add_color, std::string add_symbol) : Piece(posX, posY) {
  value = "pawn";
  symbol = add_symbol;
  color = add_color;
}