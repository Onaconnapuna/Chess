#include "bishop.h"
#include <string>

BishopPiece::BishopPiece(int posX, int posY, std::string add_color) : Piece(posX, posY) {
  value = "bishop";
  color = add_color;
}