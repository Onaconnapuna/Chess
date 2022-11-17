#include "queen.h"
#include <string>

QueenPiece::QueenPiece(int posX, int posY, std::string add_color) : Piece(posX, posY) {
  value = "queen";
  color = add_color;
}