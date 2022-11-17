#include "king.h"
#include <string>

KingPiece::KingPiece(int posX, int posY, std::string add_color) : Piece(posX, posY) {
  value = "king";
  color = add_color;
}