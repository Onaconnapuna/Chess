#include "king.h"
#include <string>

KingPiece::KingPiece(int posX, int posY, std::string color) : Piece(posX, posY) {
  value = "king";
  color = color;
}