#include "knight.h"
#include <string>

KnightPiece::KnightPiece(int posX, int posY, std::string add_color) : Piece(posX, posY) {
  value = "knight";
  color = add_color;
}